use crate::data::config::LauncherConfig;
use crate::data::model::Manifest;

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
    FileChecked(String),
    DownloadProgress { current: u64, total: u64 },
    PatchComplete,

    // Launch
    LaunchGame,
    GameLaunched(Result<(), String>),

    // General
    ErrorOccurred(String),
    Tick,
}
