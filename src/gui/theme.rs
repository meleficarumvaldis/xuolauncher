use iced::Color;

// --- Palette ---

// App Background: #151725
pub const BACKGROUND: Color = Color::from_rgb(0.082, 0.090, 0.145);

// Card Background (Surface): #1f2133
// We will apply transparency in the style function, or define a base color here.
pub const SURFACE: Color = Color::from_rgb(0.122, 0.129, 0.200);

// Accent Primary: #00d39e (Vibrant Green)
pub const ACCENT_PRIMARY: Color = Color::from_rgb(0.0, 0.827, 0.620);

// Accent Secondary: #7e57c2 (Rich Purple)
pub const ACCENT_SECONDARY: Color = Color::from_rgb(0.494, 0.341, 0.761);

pub const TEXT_BRIGHT: Color = Color::from_rgb(1.0, 1.0, 1.0);
pub const TEXT_MUTED: Color = Color::from_rgb(0.8, 0.8, 0.8); // Light gray for body text

// --- Typography & Spacing ---

pub const SPACING_DEFAULT: f32 = 20.0;
pub const SPACING_SMALL: f32 = 10.0;
pub const BORDER_RADIUS: f32 = 10.0; // Updated to 10.0 as requested
pub const FONT_SIZE_DEFAULT: u16 = 16;
pub const FONT_SIZE_HEADER: u16 = 24;
