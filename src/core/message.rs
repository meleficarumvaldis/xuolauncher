use crate::core::config::LauncherConfig;
use crate::core::manifest::{Manifest, Asset};

#[derive(Debug, Clone)]
pub enum Message {
    // Application Lifecycle
    Loaded(Result<LauncherConfig, String>),

    // Installer Interactions
    PathSelected(String),
    RulesAccepted,
    InstallStarted,
    InstallComplete(Result<(), String>),

    // Patcher
    ManifestFetched(Result<Manifest, String>),
    VerificationComplete(Vec<Asset>),
    FileChecked(String),
    /// Current downloaded bytes, Total bytes for current file (or overall?), Overall progress 0.0-1.0
    DownloadProgress {
        file: String,
        downloaded: u64,
        total: u64, // Total for this file
    },
    FileDownloaded(Asset), // Added for tracking completed files
    PatchComplete,
    PatchError(String),
    RetryPatch,

    // Launch
    PlayClicked,
    GameLaunched(Result<(), String>),

    // General
    ErrorOccurred(String),
    Tick,
}
