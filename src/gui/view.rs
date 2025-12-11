use iced::widget::{button, column, container, text, text_input, vertical_space};
use iced::{Element, Length, Alignment};
use crate::core::state::{AppState, InstallerState, PatcherState, OptionsState};
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

                text("Drücke 'Weiter', um die Installation zu beginnen.")
                    .color(theme::TEXT_MUTED),

                button(text("Weiter").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::InstallerNextStep)
            ]
            .spacing(theme::SPACING_DEFAULT)
            .align_x(Alignment::Center);

            container(content)
                .style(style::card_style)
                .padding(30)
                .max_width(600)
                .into()
        }
        InstallerState::DefinePath => {
             let content = column![
                text("Installationspfad")
                    .size(theme::FONT_SIZE_HEADER)
                    .color(theme::TEXT_BRIGHT),

                // Selectable Installation Path using TextInput
                text("Wähle den Ordner für die Installation:").color(theme::TEXT_MUTED),
                text_input("", &installer::get_default_install_path().to_string_lossy())
                    .style(style::transparent_text_input_style)
                    .width(Length::Fill)
                    .on_input(Message::PathSelected), // Allow manual typing

                // In real UI, a text input and "Browse" button would be here.
                button(text("Weiter").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
                    .style(style::primary_button_style)
                    .padding(15)
                    .on_press(Message::InstallerNextStep)
            ]
            .spacing(theme::SPACING_DEFAULT)
            .align_x(Alignment::Center);

            container(content)
                .style(style::card_style)
                .padding(30)
                .max_width(600)
                .into()
        }
        InstallerState::Options(opt_state) => {
            view_options(opt_state)
        }
        InstallerState::Setup => {
            container(text("Verzeichnisse werden erstellt...").color(theme::TEXT_BRIGHT))
                .style(style::card_style)
                .padding(30)
                .into()
        },
    }
}

fn view_options(state: &OptionsState) -> Element<'_, Message> {
     let update_content: Element<'_, Message> = if state.checking_update {
         text("Suche nach Updates...").color(theme::TEXT_MUTED).into()
     } else if state.update_available {
         column![
             text(format!("Update verfügbar: {}", state.new_version.as_deref().unwrap_or("Unknown")))
                .color(theme::ACCENT_PRIMARY),
             button(text("Update durchführen").color(theme::BACKGROUND))
                .style(style::primary_button_style)
                .on_press(Message::PerformUpdate)
         ].spacing(10).align_x(Alignment::Center).into()
     } else {
         button(text("Auf Updates prüfen").color(theme::TEXT_BRIGHT))
             .style(style::secondary_button_style)
             .on_press(Message::CheckForUpdates)
             .into()
     };

     let content = column![
        text("Optionen").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),

        container(update_content)
            .width(Length::Fill)
            .align_x(Alignment::Center),

        vertical_space().height(20),

        button(text("Installation Abschließen").color(theme::BACKGROUND).size(theme::FONT_SIZE_DEFAULT + 2))
            .style(style::primary_button_style)
            .padding(15)
            .on_press(Message::InstallStarted)
    ]
    .spacing(theme::SPACING_DEFAULT)
    .align_x(Alignment::Center);

    container(content)
        .style(style::card_style)
        .padding(30)
        .max_width(600)
        .into()
}

fn view_patcher(state: &PatcherState) -> Element<'_, Message> {
    crate::gui::screens::patcher::view(state)
}
