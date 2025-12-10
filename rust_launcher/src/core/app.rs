use iced::{Task};
use crate::core::state::{AppState, InstallerState, PatcherState};
use crate::core::config::LauncherConfig;
use crate::core::message::Message;
use crate::core::{installer, launch};

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
                     self.state = AppState::Patcher(PatcherState {
                         progress: 0.0,
                         current_file: String::new(),
                         total_files: 0,
                         processed_files: 0,
                     });
                     self.config = config;
                     // Trigger Manifest Fetch here
                }
            }
            Message::Loaded(Err(_)) => {
                 // Assume first run if load failed (file missing)
                 self.state = AppState::Installer(InstallerState::Welcome);
                 // Initialize config with default path so we have something to work with
                 self.config.install_path = installer::get_default_install_path();
            }
            Message::PathSelected(path_str) => {
                self.config.install_path = std::path::PathBuf::from(path_str);
                self.state = AppState::Installer(InstallerState::Rules);
            }
            Message::RulesAccepted => {
                // Rules accepted, proceed to setup
                let path = self.config.install_path.clone();
                // Transition state to indicate work is happening
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
                self.state = AppState::Patcher(PatcherState {
                    progress: 0.0,
                    current_file: String::new(),
                    total_files: 0,
                    processed_files: 0,
                });
                // Start patching...
            }
            Message::InstallComplete(Err(e)) => {
                self.state = AppState::Error(e);
            }
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
                // Game launched, maybe close launcher or go back to Ready
                self.state = AppState::Ready;
            }
            // ... handle other messages
            _ => {}
        }
        Task::none()
    }
}
