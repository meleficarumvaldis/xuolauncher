use std::path::{Path, PathBuf};
use directories::UserDirs;
use crate::data::config::LauncherConfig;

pub const SHARD_NAME: &str = "MyShardName";

pub fn get_default_install_path() -> PathBuf {
    if let Some(user_dirs) = UserDirs::new() {
        // Force path: UserHome/Games/MyShardName
        let mut path = user_dirs.home_dir().to_path_buf();
        path.push("Games");
        path.push(SHARD_NAME);
        path
    } else {
        PathBuf::from(format!("./{}", SHARD_NAME))
    }
}

pub fn check_first_run(config_path: &Path) -> bool {
    // If config doesn't exist or setup_completed is false, it's first run
    if !config_path.exists() {
        return true;
    }

    // In a real scenario, we would read the toml and check setup_completed
    // For this draft, existence check is the primary trigger
    false
}

// Logic to create directory structure and save initial config
pub async fn run_first_setup(install_path: PathBuf) -> Result<LauncherConfig, String> {
    tokio::fs::create_dir_all(&install_path).await
        .map_err(|e| format!("Failed to create directory: {}", e))?;

    let mut config = LauncherConfig::default();
    config.install_path = install_path;
    config.setup_completed = true;

    // Save config logic would go here (e.g. serialize to toml and write to file)

    Ok(config)
}
