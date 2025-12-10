mod core;
mod gui;
mod net;

use iced::application;
use crate::core::app::LauncherApp;
use crate::gui::view;

pub fn main() -> iced::Result {
    application(LauncherApp::title, LauncherApp::update, view::view)
        .run_with(LauncherApp::new)
}
