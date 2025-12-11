use iced::widget::{button, column, container, text, text_input, vertical_space};
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
        AppState::Patcher(state) => crate::gui::screens::patcher::view(state),
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
                    .size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                text("Drücke 'Weiter', um die Installation zu beginnen.").color(theme::TEXT_MUTED),
                button(text("Weiter").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::InstallerNextStep)
            ].spacing(theme::SPACING_DEFAULT).align_x(Alignment::Center);

            container(content).style(style::card_style).padding(30).max_width(600).into()
        }
        InstallerState::DefinePath => {
             let content = column![
                text("Installationspfad").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                text("Wähle den Ordner für die Installation:").color(theme::TEXT_MUTED),
                text_input("", &installer::get_default_install_path().to_string_lossy())
                    .style(style::transparent_text_input_style)
                    .width(Length::Fill)
                    .on_input(Message::PathSelected),
                
                // Button startet jetzt direkt die Installation
                button(text("Installation starten").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::InstallStarted)
            ].spacing(theme::SPACING_DEFAULT).align_x(Alignment::Center);

            container(content).style(style::card_style).padding(30).max_width(600).into()
        }
        InstallerState::Setup => {
            container(text("Verzeichnisse werden erstellt...").color(theme::TEXT_BRIGHT))
                .style(style::card_style).padding(30).into()
        },
        _ => text("Unbekannter Status").into() // Options skipped
    }
}