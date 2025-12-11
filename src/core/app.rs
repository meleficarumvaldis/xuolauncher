use iced::Task;
use crate::core::state::{AppState, InstallerState, PatcherState, PatcherStep};
use crate::core::config::LauncherConfig;
use crate::core::message::Message;
use crate::core::manifest::{Manifest, Asset, AssetSource};
use crate::core::{installer, launcher, verifier, launcher_installer};
use crate::net::downloader;
use serde::Deserialize;

#[derive(Deserialize)]
struct RemoteManifestItem { file: String, hash: String }

pub struct LauncherApp {
    pub state: AppState,
    pub config: LauncherConfig,
}

impl Default for LauncherApp {
    fn default() -> Self {
        Self { state: AppState::Initializing, config: LauncherConfig::default() }
    }
}

impl LauncherApp {
    pub fn new() -> (Self, Task<Message>) {
        let app = Self::default();
        (app, Task::perform(async {
            let path = installer::get_default_install_path();
            match LauncherConfig::load_from_path(&path) {
                Ok(config) => Message::Loaded(Ok(config)),
                Err(_) => Message::Loaded(Err("Config not found".to_string())),
            }
        }, |msg| msg))
    }

    pub fn title(&self) -> String { String::from("XUO Launcher") }

    pub fn update(&mut self, message: Message) -> Task<Message> {
        match message {
            Message::Loaded(Ok(config)) => {
                if !config.setup_completed {
                     self.state = AppState::Installer(InstallerState::Welcome);
                     self.config = config;
                } else {
                     self.state = AppState::ReadyToPlay;
                     self.config = config;
                }
            }
            Message::Loaded(Err(_)) => {
                 self.state = AppState::Installer(InstallerState::Welcome);
                 self.config.install_path = installer::get_default_install_path();
            }

            Message::InstallerNextStep => {
                if let AppState::Installer(InstallerState::Welcome) = &self.state {
                    self.state = AppState::Installer(InstallerState::DefinePath);
                }
            }
            Message::PathSelected(path_str) => {
                self.config.install_path = std::path::PathBuf::from(path_str);
            }
            Message::InstallStarted => {
                let path = self.config.install_path.clone();
                self.state = AppState::Installer(InstallerState::Setup);
                return Task::perform(installer::run_first_setup(path), |res| {
                    match res {
                        Ok(_) => Message::InstallComplete(Ok(())),
                        Err(e) => Message::InstallComplete(Err(e)),
                    }
                });
            }
            Message::InstallComplete(Ok(_)) => {
                self.config.setup_completed = true;
                let _ = self.config.save_to_path(&installer::get_default_install_path());
                self.state = AppState::ReadyToPlay;
            }
            Message::InstallComplete(Err(e)) => { self.state = AppState::Error(e); }

            Message::PlayClicked => {
                self.state = AppState::Patcher(PatcherState::default());
                return self.step_check_launcher();
            }
            Message::LauncherInstalled(Ok(_)) => {
                if let AppState::Patcher(ref mut p) = self.state {
                    p.status_text = "Lade Manifest...".to_string();
                }
                return self.step_fetch_manifest();
            }
            Message::LauncherInstalled(Err(e)) => { self.state = AppState::Error(e); }
            Message::ManifestFetched(Ok(manifest)) => {
                if let AppState::Patcher(ref mut p) = self.state {
                    p.status_text = "Verifiziere Dateien...".to_string();
                    p.state = PatcherStep::Checking;
                }
                let install_path = self.config.install_path.clone();
                return Task::perform(async move {
                    verifier::verify_files(&install_path, &manifest).await
                }, Message::VerificationComplete);
            }
            Message::VerificationComplete(missing) => {
                if missing.is_empty() { return Task::done(Message::PatchComplete); }
                if let AppState::Patcher(ref mut p) = self.state {
                    p.state = PatcherStep::Downloading;
                    p.total_files = missing.len();
                    p.processed_files = 0;
                    p.assets_to_download = missing;
                }
            }
            Message::FileDownloaded(asset) => {
                 if let AppState::Patcher(ref mut p) = self.state {
                     p.processed_files += 1;
                     p.files_remaining = p.total_files.saturating_sub(p.processed_files);
                     p.total_bytes_downloaded += asset.size;
                     if p.total_files > 0 { p.progress = p.processed_files as f32 / p.total_files as f32; }
                 }
            }
            Message::PatchComplete => {
                self.state = AppState::Launching;
                let c = self.config.clone();
                return Task::perform(async move {
                     tokio::task::spawn_blocking(move || launcher::launch_game(&c)).await.map_err(|e| e.to_string())?
                }, |r| Message::GameLaunched(r));
            }
            Message::GameLaunched(Ok(_)) => { self.state = AppState::ReadyToPlay; }
            Message::GameLaunched(Err(e)) => { self.state = AppState::Error(e); }
            Message::OpenLink(url) => { let _ = open::that(url); }
            _ => {}
        }
        Task::none()
    }

    fn step_check_launcher(&mut self) -> Task<Message> {
        if let AppState::Patcher(ref mut p) = self.state {
            p.status_text = "Prüfe Launcher...".to_string();
        }
        let install_path = self.config.install_path.clone();
        Task::perform(async move {
             launcher_installer::install_classicuo_launcher(&install_path).await
        }, Message::LauncherInstalled)
    }

    fn step_fetch_manifest(&self) -> Task<Message> {
        Task::perform(async move {
             let client = reqwest::Client::new();
             let res = client.get("https://alte-schattenwelt.de/datafiles/checksums.json").send().await.map_err(|e| e.to_string())?;
             let items: Vec<RemoteManifestItem> = res.json().await.map_err(|e| e.to_string())?;
             let mut m = Manifest::new();
             for item in items {
                 m.assets.push(Asset {
                     path: item.file.clone(), hash: item.hash, size: 0,
                     source: AssetSource::Official, url: format!("https://alte-schattenwelt.de/datafiles/{}", item.file),
                 });
             }
             Ok(m)
         }, Message::ManifestFetched)
    }

    pub fn view(&self) -> iced::Element<'_, Message> { crate::gui::view::view(self) }
    pub fn subscription(&self) -> iced::Subscription<Message> {
         if let AppState::Patcher(p) = &self.state {
             if p.state == PatcherStep::Downloading && !p.assets_to_download.is_empty() {
                  return iced::Subscription::run_with_id("dl", downloader::download_assets(p.assets_to_download.clone(), self.config.install_path.clone()));
             }
         }
         iced::Subscription::none()
    }
}