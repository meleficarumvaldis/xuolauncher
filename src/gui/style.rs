use iced::widget::{button, container};
use iced::{Background, Color};
use crate::gui::theme;

// Define a custom theme enum if needed, or just implement styling functions/structs.
// Since iced 0.13 uses a Catalog trait for theming, we can use the built-in Theme or define our own.
// For simplicity and immediate visual changes, we will define style functions or implement the StyleSheet traits (which are now part of the widget API in a way).
//
// Actually, in Iced 0.12+, the styling API changed. It uses `theme::Container` etc.
// But `iced` crate documentation shows `container::Style` and `Catalog`.
//
// Let's implement simple style functions that return `container::Style` and `button::Style`.

pub fn main_container_style(theme: &iced::Theme) -> container::Style {
    container::Style {
        background: Some(Background::Color(theme::BACKGROUND)),
        text_color: Some(theme::TEXT_BRIGHT),
        ..Default::default()
    }
}

pub fn primary_button_style(theme: &iced::Theme, status: button::Status) -> button::Style {
    let base = button::Style {
        background: Some(Background::Color(theme::ACCENT_PRIMARY)),
        text_color: theme::BACKGROUND, // Dark text on bright accent
        border: iced::Border {
            radius: theme::BORDER_RADIUS.into(),
            width: 0.0,
            color: Color::TRANSPARENT,
        },
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
