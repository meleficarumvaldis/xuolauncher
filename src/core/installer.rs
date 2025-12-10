use std::path::PathBuf;
use directories::UserDirs;
use crate::core::config::LauncherConfig;

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

// Logic to create directory structure and save initial config
pub async fn run_first_setup(install_path: PathBuf) -> Result<LauncherConfig, String> {
    let bin_path = install_path.join("bin");
    let data_path = install_path.join("data");

    // 1. Create directories
    tokio::fs::create_dir_all(&install_path).await
        .map_err(|e| format!("Failed to create install directory: {}", e))?;
    tokio::fs::create_dir_all(&bin_path).await
        .map_err(|e| format!("Failed to create bin directory: {}", e))?;
    tokio::fs::create_dir_all(&data_path).await
        .map_err(|e| format!("Failed to create data directory: {}", e))?;

    // 2. Prepare config
    let mut config = LauncherConfig::default();
    config.install_path = install_path.clone();
    config.setup_completed = true;

    // 3. Save config
    // We use std::fs inside save_to_path, which is blocking.
    // However, for a one-time setup operation, it's acceptable.
    // To be strictly async, we could read the logic from config::save_to_path and reimplement with tokio::fs
    // or wrap it in spawn_blocking. Given it's small text file, simple wrapper is fine.

    let config_clone = config.clone();
    let path_clone = install_path.clone();

    // Using spawn_blocking for the file write to avoid blocking the async runtime
    tokio::task::spawn_blocking(move || {
        config_clone.save_to_path(&path_clone)
    }).await
    .map_err(|e| format!("Task join error: {}", e))?
    .map_err(|e| format!("Failed to save config: {}", e))?;

    Ok(config)
}
