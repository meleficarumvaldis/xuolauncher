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
        AppState::Initializing => text("Loading...").color(theme::TEXT_BRIGHT).into(),
        AppState::Installer(state) => view_installer(state),
        AppState::Patcher(state) => view_patcher(state),
        AppState::Ready => {
            column![
                text("Ready to Play!").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                button(text("Launch Game").color(theme::BACKGROUND))
                    .style(style::primary_button_style)
                    .on_press(Message::LaunchGame)
            ].spacing(theme::SPACING_DEFAULT).into()
        }
        AppState::Launching => text("Launching...").color(theme::TEXT_BRIGHT).into(),
        AppState::Error(e) => text(format!("Error: {}", e)).color(theme::ACCENT_PRIMARY).into(),
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
                text("Welcome to MyShard Launcher").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                text(format!("Default Install Path: {:?}", installer::get_default_install_path())).color(theme::TEXT_BRIGHT),
                // In real UI, a text input and "Browse" button would be here.
                // For now, a button to accept default.
                button(text("Next").color(theme::BACKGROUND))
                    .style(style::primary_button_style)
                    .on_press(Message::PathSelected(installer::get_default_install_path().to_string_lossy().to_string()))
            ].spacing(theme::SPACING_DEFAULT).into()
        }
        InstallerState::Rules => {
                column![
                text("Server Rules").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
                container(
                    scrollable(
                        text("1. Be nice.\n2. No cheating.\n3. Have fun.\n\n(Scroll for more...)")
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
                button(text("I Accept").color(theme::BACKGROUND))
                    .style(style::primary_button_style)
                    .on_press(Message::RulesAccepted)
            ].spacing(theme::SPACING_DEFAULT).into()
        }
        InstallerState::Setup => text("Setting up directories...").color(theme::TEXT_BRIGHT).into(),
    }
}

fn view_patcher(state: &PatcherState) -> Element<'_, Message> {
    column![
        text("Patching...").size(theme::FONT_SIZE_HEADER).color(theme::TEXT_BRIGHT),
        progress_bar(0.0..=1.0, state.progress).style(|_| progress_bar::Style {
            background: theme::SURFACE.into(),
            bar: theme::ACCENT_SECONDARY.into(),
            border: Border {
                radius: theme::BORDER_RADIUS.into(),
                width: 0.0,
                color: iced::Color::TRANSPARENT,
            },
        }),
        text(state.current_file.clone()).color(theme::TEXT_MUTED)
    ].spacing(theme::SPACING_DEFAULT).into()
}
