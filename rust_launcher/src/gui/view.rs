use iced::widget::{button, column, container, progress_bar, text, scrollable};
use iced::{Element, Length};
use crate::core::state::{AppState, InstallerState, PatcherState};
use crate::core::message::Message;
use crate::core::installer;
use crate::core::app::LauncherApp;

pub fn view(app: &LauncherApp) -> Element<'_, Message> {
    let content = match &app.state {
        AppState::Initializing => text("Loading...").into(),
        AppState::Installer(state) => view_installer(state),
        AppState::Patcher(state) => view_patcher(state),
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

fn view_installer(state: &InstallerState) -> Element<'_, Message> {
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
        InstallerState::Setup => text("Setting up directories...").into(),
    }
}

fn view_patcher(state: &PatcherState) -> Element<'_, Message> {
    column![
        text("Patching..."),
        progress_bar(0.0..=1.0, state.progress),
        text(state.current_file.clone())
    ].spacing(20).into()
}
