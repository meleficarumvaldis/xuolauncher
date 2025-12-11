use iced::widget::{button, column, container, progress_bar, text, scrollable};
use iced::{Element, Length, Border};
use crate::core::state::{AppState, InstallerState, PatcherState};
use crate::core::message::Message;
use crate::core::installer;
use crate::core::app::LauncherApp;
use crate::gui::style;
use crate::gui::theme;

pub fn view(app: &LauncherApp) -> Element<'_, Message> {
    let content = match &app.state {
        AppState::Initializing => text("Lade...").color(theme::TEXT_BRIGHT).into(),
        AppState::Installer(state) => view_installer(state),
        AppState::Patcher(state) => view_patcher(state),
        AppState::ReadyToPlay => crate::gui::screens::dashboard::view(),
        AppState::Launching => text("Spiel startet...").color(theme::TEXT_BRIGHT).into(),
        AppState::Error(e) => text(format!("Fehler: {}", e)).color(theme::ACCENT_PRIMARY).into(),
    };

    container(content)
        .width(Length::Fill)
        .height(Length::Fill)
        .center_x(Length::Fill)
        .center_y(Length::Fill)
        .style(style::main_container_style)
        .into()
}

fn view_installer(state: &InstallerState) -> Element<'_, Message> {
    match state {
        InstallerState::Welcome => {
            column![
                text("Willkommen beim Launcher der alten Schattenwelt").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                text(format!("Installationspfad: {:?}", installer::get_default_install_path())).color(theme::TEXT_BRIGHT),
                // In real UI, a text input and "Browse" button would be here.
                // For now, a button to accept default.
                button(text("Weiter").color(theme::BACKGROUND))
                    .style(style::primary_button_style)
                    .on_press(Message::PathSelected(installer::get_default_install_path().to_string_lossy().to_string()))
            ].spacing(theme::SPACING_DEFAULT).into()
        }
        InstallerState::Rules => {
                column![
                text("Server Regeln").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                container(
                    scrollable(
                        text("1. Seid nett.\n2. Kein Adel.\n3. Habt Spaß.\n\n(Scroll für mehr...)")
                        .color(theme::TEXT_BRIGHT)
                    ).height(200)
                ).style(|_| container::Style {
                    background: Some(iced::Background::Color(theme::SURFACE)),
                    border: Border {
                        radius: theme::BORDER_RADIUS.into(),
                        width: 1.0,
                        color: theme::ACCENT_SECONDARY,
                    },
                    ..Default::default()
                }).padding(10),
                button(text("Akzeptieren").color(theme::BACKGROUND))
                    .style(style::primary_button_style)
                    .on_press(Message::RulesAccepted)
            ].spacing(theme::SPACING_DEFAULT).into()
        }
        InstallerState::Setup => text("Verzeichnisse werden erstellt...").color(theme::TEXT_BRIGHT).into(),
    }
}

fn view_patcher(state: &PatcherState) -> Element<'_, Message> {
    crate::gui::screens::patcher::view(state)
}
