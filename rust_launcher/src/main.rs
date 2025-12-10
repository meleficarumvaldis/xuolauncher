mod app;
mod data {
    pub mod config;
    pub mod model;
}
mod logic {
    pub mod installer;
    pub mod launch;
}
mod message;

use iced::application;
use crate::app::LauncherApp;

pub fn main() -> iced::Result {
    application(LauncherApp::title, LauncherApp::update, LauncherApp::view)
        .run_with(LauncherApp::new)
}
