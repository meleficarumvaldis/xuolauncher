use crate::core::config::LauncherConfig;
use crate::core::manifest::{Manifest, Asset};

#[derive(Debug, Clone)]
pub enum Message {
    // Application Lifecycle
    Loaded(Result<LauncherConfig, String>),

    // Installer Interactions
    InstallerNextStep,
    PathSelected(String),
    InstallStarted, // Startet jetzt direkt nach der Pfadwahl
    InstallComplete(Result<(), String>),

    // Options (werden im vereinfachten Flow ggf. übersprungen, bleiben aber im Code)
    CheckForUpdates,
    UpdateChecked(Result<Option<String>, String>),
    PerformUpdate,

    // Patcher Flow (Schritt-für-Schritt)
    LauncherInstalled(Result<(), String>), // NEW: Rückmeldung nach Schritt 1
    ManifestFetched(Result<Manifest, String>),
    VerificationComplete(Vec<Asset>),
    DownloadProgress {
        file: String,
        downloaded: u64,
        total: u64,
    },
    FileDownloaded(Asset),
    PatchComplete,
    PatchError(String),
    RetryPatch,

    // Launch
    PlayClicked,
    GameLaunched(Result<(), String>),

    // General
    ErrorOccurred(String),
    Tick,
    OpenLink(String),
}