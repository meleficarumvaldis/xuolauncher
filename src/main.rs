mod core;
mod gui;
mod net;

use iced::application;
use crate::core::app::LauncherApp;
use crate::core::self_update;

pub fn main() -> iced::Result {
    // Cleanup any old binary left over from a previous update (Windows)
    self_update::cleanup_old_binary();

    application(LauncherApp::title, LauncherApp::update, LauncherApp::view)
        .subscription(LauncherApp::subscription)
        .run_with(LauncherApp::new)
}
