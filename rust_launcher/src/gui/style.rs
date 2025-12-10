// Placeholder for styling logic (Theme, Colors, etc.)
use iced::{color, Color};

pub struct Theme {
    pub background: Color,
    pub text: Color,
    pub accent: Color,
}

impl Default for Theme {
    fn default() -> Self {
        Self {
            background: color!(0x1e, 0x1e, 0x2e), // Dark background (Catppuccin Mocha base-ish)
            text: color!(0xcd, 0xd6, 0xf4),       // Light text
            accent: color!(0x89, 0xb4, 0xfa),     // Blue accent
        }
    }
}
