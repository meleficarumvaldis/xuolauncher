use iced::widget::{button, column, container, row, text, text_input, vertical_space};
use iced::{Alignment, Element, Length};
use crate::core::message::Message;
use crate::gui::theme;
use crate::gui::style;

pub fn view() -> Element<'static, Message> {
    // Top: Server Status
    // Wrapped in a Card
    let status_card = container(
        row![
            text("Server Status:").size(theme::FONT_SIZE_DEFAULT).color(theme::TEXT_BRIGHT),
            // Selectable status
            text_input("", "Online")
                .style(style::transparent_text_input_style)
                .width(Length::Shrink) // Just wide enough for content if possible, or use fixed
        ]
        .spacing(theme::SPACING_SMALL)
        .align_y(Alignment::Center)
    )
    .style(style::card_style)
    .padding(theme::SPACING_DEFAULT)
    .width(Length::Fill);

    // Center: News Feed
    // Wrapped in a Card
    let news_feed = container(
        column![
            text("Neuigkeiten").size(theme::FONT_SIZE_HEADER).color(theme::ACCENT_PRIMARY),
            vertical_space().height(theme::SPACING_SMALL),
            text("Willkommen auf der alten Schattenwelt. Das neueste Update beinhaltet...").color(theme::TEXT_BRIGHT),
            text("- einen Keks").color(theme::TEXT_MUTED),
            text("- einem Nikolaus aus Schoki").color(theme::TEXT_MUTED),
        ]
        .spacing(theme::SPACING_SMALL)
    )
    .width(Length::Fill)
    .height(Length::Fill)
    .style(style::card_style)
    .padding(theme::SPACING_DEFAULT);

    // Bottom: SPIELEN Button
    let play_button = button(
        container(
            text("SPIELEN")
                .size(32)
                .color(theme::BACKGROUND)
        )
        .width(Length::Fill)
        .align_x(Alignment::Center)
    )
    .on_press(Message::PlayClicked)
    .style(style::primary_button_style)
    .width(Length::Fill)
    .padding(20); // Large padding

    // Footer: Icons/Links
    // Using Secondary Action Color (Purple)
    let footer = row![
        button(text("Discord").color(theme::TEXT_BRIGHT))
            .style(style::secondary_button_style)
            .on_press(Message::OpenLink("https://discord.gg/5DqQMZ8W".to_string()))
            .padding(10),
        button(text("Registrieren").color(theme::TEXT_BRIGHT))
            .style(style::secondary_button_style)
            .on_press(Message::OpenLink("https://alte-schattenwelt.de/register".to_string()))
            .padding(10),
        button(text("Wiki").color(theme::TEXT_BRIGHT))
            .style(style::secondary_button_style)
            .on_press(Message::OpenLink("https://wiki.alte-schattenwelt.de".to_string())) // Guessing wiki link or keep generic for now if unknown
            .padding(10),
    ]
    .spacing(theme::SPACING_DEFAULT)
    .align_y(Alignment::Center)
    .width(Length::Fill);

    let content = column![
        status_card,
        vertical_space().height(theme::SPACING_DEFAULT),
        news_feed,
        vertical_space().height(theme::SPACING_DEFAULT),
        play_button,
        vertical_space().height(theme::SPACING_DEFAULT),
        container(footer).width(Length::Fill).align_x(Alignment::Center) // Center footer buttons
    ]
    .spacing(theme::SPACING_DEFAULT)
    .padding(40)
    .max_width(800);

    container(content)
        .width(Length::Fill)
        .height(Length::Fill)
        .center_x(Length::Fill)
        .center_y(Length::Fill)
        .style(style::main_container_style)
        .into()
}
