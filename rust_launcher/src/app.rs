use iced::widget::{button, column, container, progress_bar, text, scrollable};
use iced::{Element, Length, Task};
use crate::data::model::{AppState, InstallerState, PatcherState};
use crate::data::config::LauncherConfig;
use crate::message::Message;
use crate::logic::{installer, launch};

pub struct LauncherApp {
    state: AppState,
    config: LauncherConfig,
    // Add other fields like manifest, current download info, etc.
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
        (app, Task::perform(async {}, |_| Message::Loaded(Ok(LauncherConfig::default()))))
        // In real app, we would read the config file here
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
            }
            Message::PathSelected(path_str) => {
                self.config.install_path = std::path::PathBuf::from(path_str);
                self.state = AppState::Installer(InstallerState::Rules);
            }
            Message::RulesAccepted => {
                // Rules accepted, proceed to setup
                let path = self.config.install_path.clone();
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

    pub fn view(&self) -> Element<Message> {
        let content = match &self.state {
            AppState::Initializing => text("Loading...").into(),
            AppState::Installer(state) => self.view_installer(state),
            AppState::Patcher(state) => self.view_patcher(state),
            AppState::Ready => {
                column![
                    text("Ready to Play!"),
                    button("Launch Game").on_press(Message::LaunchGame)
                ].into()
            }
            AppState::Launching => text("Launching...").into(),
            AppState::Error(e) => text(format!("Error: {}", e)).into(),
        };

        container(content)
            .width(Length::Fill)
            .height(Length::Fill)
            .center_x(Length::Fill)
            .center_y(Length::Fill)
            .into()
    }

    fn view_installer(&self, state: &InstallerState) -> Element<Message> {
        match state {
            InstallerState::Welcome => {
                column![
                    text("Welcome to MyShard Launcher"),
                    text(format!("Default Install Path: {:?}", installer::get_default_install_path())),
                    // In real UI, a text input and "Browse" button would be here.
                    // For now, a button to accept default.
                    button("Next").on_press(Message::PathSelected(installer::get_default_install_path().to_string_lossy().to_string()))
                ].spacing(20).into()
            }
            InstallerState::Rules => {
                 column![
                    text("Server Rules"),
                    scrollable(
                        text("1. Be nice.\n2. No cheating.\n3. Have fun.\n\n(Scroll for more...)")
                    ).height(200),
                    button("I Accept").on_press(Message::RulesAccepted)
                ].spacing(20).into()
            }
            InstallerState::Setup => text("Setting up...").into(),
        }
    }

    fn view_patcher(&self, state: &PatcherState) -> Element<Message> {
        column![
            text("Patching..."),
            progress_bar(0.0..=1.0, state.progress),
            text(state.current_file.clone())
        ].spacing(20).into()
    }
}
