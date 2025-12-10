use serde::{Deserialize, Serialize};
use std::path::PathBuf;

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
