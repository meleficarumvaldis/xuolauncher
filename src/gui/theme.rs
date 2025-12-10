use iced::Color;

// --- Palette ---

pub const BACKGROUND: Color = Color::from_rgb(0.07, 0.07, 0.07); // #121212
pub const SURFACE: Color = Color::from_rgba(0.12, 0.12, 0.12, 0.95); // #1E1E1E, alpha ~0.95
pub const ACCENT_PRIMARY: Color = Color::from_rgb(1.0, 0.84, 0.0); // #FFD700 (Golden/Amber)
pub const ACCENT_SECONDARY: Color = Color::from_rgb(0.3, 0.69, 0.31); // #4CAF50 (Muted Green)
pub const TEXT_BRIGHT: Color = Color::from_rgb(1.0, 1.0, 1.0);
pub const TEXT_MUTED: Color = Color::from_rgb(0.6, 0.6, 0.6);

// --- Typography & Spacing ---

pub const SPACING_DEFAULT: f32 = 20.0;
pub const SPACING_SMALL: f32 = 10.0;
pub const BORDER_RADIUS: f32 = 8.0;
pub const FONT_SIZE_DEFAULT: u16 = 16;
pub const FONT_SIZE_HEADER: u16 = 24;
