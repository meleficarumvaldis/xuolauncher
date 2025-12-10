use iced::widget::{button, column, container, row, text, vertical_space};
use iced::{Alignment, Element, Length};
use crate::core::message::Message;
use crate::gui::theme;
use crate::gui::style;

pub fn view() -> Element<'static, Message> {
    // Top: Server Status
    let status_indicator = row![
        text("Server Status:").size(theme::FONT_SIZE_DEFAULT).color(theme::TEXT_BRIGHT),
        text("Online").size(theme::FONT_SIZE_DEFAULT).color(theme::ACCENT_SECONDARY) // Green
    ]
    .spacing(theme::SPACING_SMALL)
    .align_y(Alignment::Center);

    // Center: News Feed (Placeholder)
    // styled as a semi-transparent glass pane
    let news_feed = container(
        column![
            text("Neuigkeiten").size(theme::FONT_SIZE_HEADER).color(theme::ACCENT_PRIMARY),
            vertical_space().height(theme::SPACING_SMALL),
            text("Willkommen auf dem Shard! Das neueste Update beinhaltet...").color(theme::TEXT_BRIGHT),
            text("- Neue Dungeons").color(theme::TEXT_MUTED),
            text("- PvP Balance").color(theme::TEXT_MUTED),
        ]
        .spacing(theme::SPACING_SMALL)
    )
    .width(Length::Fill)
    .height(Length::Fill)
    .style(|_theme| container::Style {
        background: Some(iced::Background::Color(iced::Color { a: 0.3, ..theme::SURFACE })),
        border: iced::Border {
            radius: theme::BORDER_RADIUS.into(),
            width: 1.0,
            color: theme::ACCENT_PRIMARY,
        },
        ..Default::default()
    })
    .padding(theme::SPACING_DEFAULT);

    // Bottom: SPIELEN Button
    let play_button = button(
        container(
            text("SPIELEN")
                .size(32) // Epic size
                .color(theme::BACKGROUND)
        )
        .width(Length::Fill)
        .align_x(Alignment::Center)
    )
    .on_press(Message::PlayClicked)
    .style(|theme: &iced::Theme, status| {
        let base = button::Style {
            background: Some(iced::Background::Color(theme::ACCENT_PRIMARY)),
            text_color: theme::BACKGROUND,
            border: iced::Border {
                radius: 12.0.into(), // Slightly simpler radius handling
                width: 0.0,
                color: iced::Color::TRANSPARENT,
            },
            ..button::Style::default()
        };
        match status {
            button::Status::Hovered => button::Style {
                background: Some(iced::Background::Color(iced::Color { a: 0.9, ..theme::ACCENT_PRIMARY })),
                ..base
            },
             _ => base
        }
    })
    .width(Length::Fill)
    .padding(15);

    // Footer: Icons
    // We'll use text buttons as placeholders for icons if we don't have SVGs handy, or load SVGs if available.
    // For now, text buttons [Discord] [Wiki] [Web]
    let footer = row![
        button(text("Discord").color(theme::TEXT_BRIGHT)).style(style::primary_button_style).on_press(Message::Tick), // Dummy action
        button(text("Wiki").color(theme::TEXT_BRIGHT)).style(style::primary_button_style).on_press(Message::Tick),
        button(text("Website").color(theme::TEXT_BRIGHT)).style(style::primary_button_style).on_press(Message::Tick),
    ]
    .spacing(theme::SPACING_DEFAULT)
    .align_y(Alignment::Center);

    let content = column![
        status_indicator,
        vertical_space().height(theme::SPACING_DEFAULT),
        news_feed,
        vertical_space().height(theme::SPACING_DEFAULT),
        play_button,
        vertical_space().height(theme::SPACING_DEFAULT),
        footer
    ]
    .spacing(theme::SPACING_DEFAULT)
    .padding(40) // Add some padding around the whole dashboard
    .max_width(800);

    container(content)
        .width(Length::Fill)
        .height(Length::Fill)
        .center_x(Length::Fill)
        .center_y(Length::Fill)
        .style(style::main_container_style)
        .into()
}
