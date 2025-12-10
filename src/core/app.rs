use iced::{Task};
use crate::core::state::{AppState, InstallerState, PatcherState, PatcherStep};
use crate::core::config::LauncherConfig;
use crate::core::message::Message;
use crate::core::manifest::{Manifest, Asset, AssetSource};
use crate::core::{installer, launch, verifier};
use crate::net::downloader;

pub struct LauncherApp {
    pub state: AppState,
    pub config: LauncherConfig,
}

impl Default for LauncherApp {
    fn default() -> Self {
        Self {
            state: AppState::Initializing,
            config: LauncherConfig::default(),
        }
    }
}

impl LauncherApp {
    pub fn new() -> (Self, Task<Message>) {
        let app = Self::default();
        // Start by loading config or checking first run
        (app, Task::perform(async {
            let path = installer::get_default_install_path();
            match LauncherConfig::load_from_path(&path) {
                Ok(config) => Message::Loaded(Ok(config)),
                Err(_) => Message::Loaded(Err("Config not found".to_string())),
            }
        }, |msg| msg))
    }

    pub fn title(&self) -> String {
        String::from("XUO Launcher (Rust)")
    }

    pub fn update(&mut self, message: Message) -> Task<Message> {
        match message {
            Message::Loaded(Ok(config)) => {
                // Check if setup is completed
                if !config.setup_completed {
                     self.state = AppState::Installer(InstallerState::Welcome);
                     self.config = config;
                } else {
                     self.state = AppState::Patcher(PatcherState::default());
                     self.config = config;
                     return self.start_patching();
                }
            }
            Message::Loaded(Err(_)) => {
                 self.state = AppState::Installer(InstallerState::Welcome);
                 self.config.install_path = installer::get_default_install_path();
            }
            Message::PathSelected(path_str) => {
                self.config.install_path = std::path::PathBuf::from(path_str);
                self.state = AppState::Installer(InstallerState::Rules);
            }
            Message::RulesAccepted => {
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
                self.state = AppState::Patcher(PatcherState::default());
                return self.start_patching();
            }
            Message::InstallComplete(Err(e)) => {
                self.state = AppState::Error(e);
            }

            // --- Patcher Messages ---
            Message::ManifestFetched(Ok(manifest)) => {
                if let AppState::Patcher(ref mut p_state) = self.state {
                    p_state.state = PatcherStep::Checking;
                }
                let install_path = self.config.install_path.clone();
                return Task::perform(async move {
                    verifier::verify_files(&install_path, &manifest).await
                }, Message::VerificationComplete);
            }
            Message::ManifestFetched(Err(e)) => {
                self.state = AppState::Error(format!("Failed to fetch manifest: {}", e));
            }
            Message::VerificationComplete(missing_assets) => {
                if missing_assets.is_empty() {
                    return Task::done(Message::PatchComplete);
                } else {
                    if let AppState::Patcher(ref mut p_state) = self.state {
                        p_state.state = PatcherStep::Downloading;
                        p_state.total_files = missing_assets.len();
                        p_state.processed_files = 0;
                        p_state.assets_to_download = missing_assets;

                        // Calculate total bytes
                        p_state.total_bytes_to_download = p_state.assets_to_download.iter().map(|a| a.size).sum();
                        p_state.total_bytes_downloaded = 0;
                    }
                }
            }
            Message::DownloadProgress { file, downloaded, total } => {
                if let AppState::Patcher(ref mut p_state) = self.state {
                    p_state.current_file = file;
                    // We need a way to track cumulative progress.
                    // This simple update doesn't account for other files' downloaded bytes effectively unless we track per-file state map.
                    // For now, let's approximate or just rely on file completion for big jumps, and use this for current file activity.
                    // Or, we could just ignore `total` here and rely on `downloaded` delta if we had previous value.

                    // Ideally `p_state.total_bytes_downloaded` should update.
                    // Since we don't track per-file state in PatcherState easily (would need a HashMap),
                    // we will just show "Downloading: File X" and maybe overall progress based on `processed_files / total_files`.

                    // Refinement: use `processed_files` count for the main progress bar for stability.
                    if p_state.total_files > 0 {
                         let base_progress = p_state.processed_files as f32 / p_state.total_files as f32;
                         let file_progress = if total > 0 { downloaded as f32 / total as f32 } else { 0.0 };
                         // Add a fraction of 1/total_files based on current file progress
                         p_state.progress = base_progress + (file_progress / p_state.total_files as f32);
                    }

                    p_state.download_speed = "Calculating...".to_string(); // Todo: real speed calc requires time tracking
                }
            }
            Message::FileDownloaded(asset) => {
                 if let AppState::Patcher(ref mut p_state) = self.state {
                     p_state.processed_files += 1;
                     p_state.files_remaining = p_state.total_files.saturating_sub(p_state.processed_files);
                     p_state.total_bytes_downloaded += asset.size;
                 }
            }
            Message::PatchComplete => {
                self.state = AppState::Ready;
            }
            Message::PatchError(e) => {
                self.state = AppState::Error(e);
            }
            Message::RetryPatch => {
                self.state = AppState::Patcher(PatcherState::default());
                return self.start_patching();
            }

            // Launch
            Message::LaunchGame => {
                if let AppState::Ready = self.state {
                    self.state = AppState::Launching;
                    let config_clone = self.config.clone();
                    return Task::perform(async move {
                         launch::inject_settings(&config_clone).await?;
                         launch::launch_game(&config_clone).await
                    }, |res| Message::GameLaunched(res));
                }
            }
            Message::GameLaunched(Err(e)) => {
                self.state = AppState::Error(e);
            }
            Message::GameLaunched(Ok(_)) => {
                self.state = AppState::Ready;
            }
            // ... handle other messages
            _ => {}
        }
        Task::none()
    }

    fn start_patching(&self) -> Task<Message> {
         // Mock fetching manifest for now
         Task::perform(async {
             // Simulate "official_manifest.json" and "custom_manifest.json"
             // Since we are mocking, we will just construct a manifest with a few test assets.
             // In production, this would use `reqwest` to fetch JSON from a URL.

             let mut official = Manifest::new();
             // Add a fake asset that definitely won't match local to trigger download
             official.assets.push(Asset {
                 path: "test_asset.txt".to_string(),
                 hash: "dummy_hash".to_string(), // Will mismatch
                 size: 1024,
                 source: AssetSource::Official,
                 url: "https://httpbin.org/bytes/1024".to_string(), // Use httpbin to simulate download
             });

             let mut custom = Manifest::new();
             custom.assets.push(Asset {
                 path: "custom_asset.txt".to_string(),
                 hash: "custom_hash".to_string(),
                 size: 2048,
                 source: AssetSource::Custom,
                 url: "https://httpbin.org/bytes/2048".to_string(),
             });

             official.merge(custom);

             Ok(official)
         }, Message::ManifestFetched)
    }

    pub fn view(&self) -> iced::Element<Message> {
        match &self.state {
             AppState::Initializing => iced::widget::text("Initializing...").into(),
             AppState::Installer(_) => iced::widget::text("Installer Placeholder").into(),
             AppState::Patcher(state) => crate::gui::screens::patcher::view(state),
             AppState::Ready => iced::widget::button("Play").on_press(Message::LaunchGame).into(),
             AppState::Launching => iced::widget::text("Launching...").into(),
             AppState::Error(e) => iced::widget::column![
                 iced::widget::text(format!("Error: {}", e)),
                 iced::widget::button("Retry").on_press(Message::RetryPatch)
             ].into(),
        }
    }

    pub fn subscription(&self) -> iced::Subscription<Message> {
         if let AppState::Patcher(patcher_state) = &self.state {
             if patcher_state.state == PatcherStep::Downloading && !patcher_state.assets_to_download.is_empty() {
                  return iced::Subscription::run_with_id(
                      "download",
                      downloader::download_assets(
                          patcher_state.assets_to_download.clone(),
                          self.config.install_path.clone()
                      )
                  );
             }
         }
         iced::Subscription::none()
    }
}
