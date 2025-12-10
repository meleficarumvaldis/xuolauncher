use serde::{Deserialize, Serialize};
use std::path::{Path, PathBuf};
use std::fs;

#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct LauncherConfig {
    pub setup_completed: bool,
    pub install_path: PathBuf,
    pub last_server_ip: String,
    pub last_server_port: u16,
    pub client_version: String,
}

impl Default for LauncherConfig {
    fn default() -> Self {
        Self {
            setup_completed: false,
            install_path: PathBuf::new(),
            last_server_ip: "127.0.0.1".to_string(),
            last_server_port: 2593,
            client_version: "7.0.15.1".to_string(),
        }
    }
}

impl LauncherConfig {
    /// Tries to load the configuration from `launcher.toml` in the given directory.
    pub fn load_from_path(path: &Path) -> Result<Self, String> {
        let config_path = path.join("launcher.toml");
        if !config_path.exists() {
            return Err("Config file not found".to_string());
        }

        let content = fs::read_to_string(&config_path)
            .map_err(|e| format!("Failed to read config file: {}", e))?;

        toml::from_str(&content)
            .map_err(|e| format!("Failed to parse config file: {}", e))
    }

    /// Saves the configuration to `launcher.toml` in the given directory.
    pub fn save_to_path(&self, path: &Path) -> Result<(), String> {
         let config_path = path.join("launcher.toml");
         let content = toml::to_string_pretty(self)
             .map_err(|e| format!("Failed to serialize config: {}", e))?;

         fs::write(&config_path, content)
             .map_err(|e| format!("Failed to write config file: {}", e))
    }
}
