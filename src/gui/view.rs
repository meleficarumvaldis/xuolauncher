use iced::widget::{button, column, container, text, scrollable, text_input};
use iced::{Element, Length, Alignment};
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
            let content = column![
                text("Willkommen beim Launcher der alten Schattenwelt")
                    .size(theme::FONT_SIZE_HEADER)
                    .color(theme::TEXT_BRIGHT),

                // Selectable Installation Path using TextInput
                text("Installationspfad:").color(theme::TEXT_MUTED),
                text_input("", &installer::get_default_install_path().to_string_lossy())
                    .style(style::transparent_text_input_style)
                    .width(Length::Fill),

                // In real UI, a text input and "Browse" button would be here.
                // For now, a button to accept default.
                button(text("Weiter").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::PathSelected(installer::get_default_install_path().to_string_lossy().to_string()))
            ]
            .spacing(theme::SPACING_DEFAULT)
            .align_x(Alignment::Center);

            container(content)
                .style(style::card_style)
                .padding(30)
                .max_width(600)
                .into()
        }
        InstallerState::Rules => {
            let content = column![
                text("Server Regeln").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                container(
                    scrollable(
                        text("1. Seid nett.\n2. Kein Adel.\n3. Habt Spaß.\n\n(Scroll für mehr...)")
                        .color(theme::TEXT_MUTED) // Muted text for body
                        .size(theme::FONT_SIZE_DEFAULT)
                    ).height(200)
                ).width(Length::Fill), // No inner style needed, outer card handles it

                button(text("Akzeptieren").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::RulesAccepted)
            ]
            .spacing(theme::SPACING_DEFAULT)
            .align_x(Alignment::Center);

            container(content)
                .style(style::card_style)
                .padding(30)
                .max_width(600)
                .into()
        }
        InstallerState::Setup => {
            container(text("Verzeichnisse werden erstellt...").color(theme::TEXT_BRIGHT))
                .style(style::card_style)
                .padding(30)
                .into()
        },
    }
}

fn view_patcher(state: &PatcherState) -> Element<'_, Message> {
    crate::gui::screens::patcher::view(state)
}
