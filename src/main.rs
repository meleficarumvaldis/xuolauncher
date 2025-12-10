mod core;
mod gui;
mod net;

use iced::application;
use crate::core::app::LauncherApp;

pub fn main() -> iced::Result {
    application(LauncherApp::title, LauncherApp::update, LauncherApp::view)
        .subscription(LauncherApp::subscription)
        .run_with(LauncherApp::new)
}
