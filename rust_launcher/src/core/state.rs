use serde::{Deserialize, Serialize};
use std::path::PathBuf;

#[derive(Debug, Clone, PartialEq, Default)]
pub enum AppState {
    #[default]
    Initializing,
    Installer(InstallerState),
    Patcher(PatcherState),
    Ready,
    Launching,
    Error(String),
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
}

#[derive(Debug, Serialize, Deserialize, Clone, PartialEq, Eq)]
pub enum AssetSource {
    Base,     // Official EA Assets
    Override, // Custom Shard Assets
    Engine,   // ClassicUO Binaries
}

#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct Asset {
    pub name: String,
    pub source: AssetSource,
    pub remote_url: String,
    pub hash_sha256: String,
    pub size_bytes: u64,
    pub relative_path: PathBuf,
}

#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct Manifest {
    pub version: String,
    pub assets: Vec<Asset>,
}
