use iced::widget::{button, container, text_input};
use iced::{Background, Color, Border, Shadow};
use crate::gui::theme;

pub fn main_container_style(_theme: &iced::Theme) -> container::Style {
    container::Style {
        background: Some(Background::Color(theme::BACKGROUND)),
        text_color: Some(theme::TEXT_BRIGHT),
        ..Default::default()
    }
}

pub fn card_style(_theme: &iced::Theme) -> container::Style {
    container::Style {
        background: Some(Background::Color(Color {
            a: 0.95, // Slight transparency
            ..theme::SURFACE
        })),
        text_color: Some(theme::TEXT_MUTED), // Default text color in cards
        border: Border {
            radius: theme::BORDER_RADIUS.into(),
            width: 0.0,
            color: Color::TRANSPARENT,
        },
        shadow: Shadow::default(),
        ..Default::default()
    }
}

pub fn primary_button_style(_theme: &iced::Theme, status: button::Status) -> button::Style {
    let base = button::Style {
        background: Some(Background::Color(theme::ACCENT_PRIMARY)),
        text_color: theme::BACKGROUND, // Dark text on bright accent
        border: Border {
            radius: theme::BORDER_RADIUS.into(),
            width: 0.0,
            color: Color::TRANSPARENT,
        },
        shadow: Shadow::default(),
        ..button::Style::default()
    };

    match status {
        button::Status::Active => base,
        button::Status::Hovered => button::Style {
            background: Some(Background::Color(Color {
                a: 0.8,
                ..theme::ACCENT_PRIMARY
            })),
            ..base
        },
        button::Status::Pressed => button::Style {
             background: Some(Background::Color(Color {
                a: 0.6,
                ..theme::ACCENT_PRIMARY
            })),
            ..base
        },
        button::Status::Disabled => button::Style {
            background: Some(Background::Color(theme::SURFACE)),
            text_color: theme::TEXT_MUTED,
            ..base
        },
    }
}

pub fn secondary_button_style(_theme: &iced::Theme, status: button::Status) -> button::Style {
    let base = button::Style {
        background: Some(Background::Color(theme::ACCENT_SECONDARY)),
        text_color: theme::TEXT_BRIGHT, // White text on purple
        border: Border {
            radius: theme::BORDER_RADIUS.into(),
            width: 0.0,
            color: Color::TRANSPARENT,
        },
        shadow: Shadow::default(),
        ..button::Style::default()
    };

    match status {
        button::Status::Active => base,
        button::Status::Hovered => button::Style {
            background: Some(Background::Color(Color {
                a: 0.8,
                ..theme::ACCENT_SECONDARY
            })),
            ..base
        },
        button::Status::Pressed => button::Style {
             background: Some(Background::Color(Color {
                a: 0.6,
                ..theme::ACCENT_SECONDARY
            })),
            ..base
        },
        button::Status::Disabled => button::Style {
            background: Some(Background::Color(theme::SURFACE)),
            text_color: theme::TEXT_MUTED,
            ..base
        },
    }
}

pub fn transparent_text_input_style(_theme: &iced::Theme, status: text_input::Status) -> text_input::Style {
    let base = text_input::Style {
        background: Background::Color(Color::TRANSPARENT),
        border: Border {
            width: 0.0,
            radius: 0.0.into(),
            color: Color::TRANSPARENT,
        },
        icon: Color::TRANSPARENT,
        placeholder: theme::TEXT_MUTED,
        value: theme::TEXT_BRIGHT,
        selection: Color::from_rgba(1.0, 1.0, 1.0, 0.2),
    };

    match status {
        text_input::Status::Active => base,
        text_input::Status::Hovered => base,
        text_input::Status::Focused => base,
        text_input::Status::Disabled => text_input::Style {
            value: theme::TEXT_MUTED,
            ..base
        },
    }
}
