use crate::core::manifest::{Asset, Manifest};
use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, PartialEq)]
pub enum AppState {
    Initializing,
    Installer(InstallerState),
    Patcher(PatcherState),
    ReadyToPlay,
    Launching,
    Error(String),
}

impl Default for AppState {
    fn default() -> Self {
        Self::Initializing
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum InstallerState {
    Welcome,
    Rules,
    Setup, // Performing directory creation
}

#[derive(Debug, Clone, PartialEq)]
pub struct PatcherState {
    pub progress: f32, // 0.0 to 1.0
    pub current_file: String,
    pub total_files: usize,
    pub processed_files: usize,
    pub state: PatcherStep,
    pub download_speed: String,
    pub files_remaining: usize,
    pub assets_to_download: Vec<Asset>,
    // Helpers for speed calculation
    pub total_bytes_to_download: u64,
    pub total_bytes_downloaded: u64,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum PatcherStep {
    Checking,
    Downloading,
}

impl Default for PatcherState {
    fn default() -> Self {
        Self {
            progress: 0.0,
            current_file: String::new(),
            total_files: 0,
            processed_files: 0,
            state: PatcherStep::Checking,
            download_speed: String::from("0 KB/s"),
            files_remaining: 0,
            assets_to_download: Vec::new(),
            total_bytes_to_download: 0,
            total_bytes_downloaded: 0,
        }
    }
}
