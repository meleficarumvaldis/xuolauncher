use serde_json::json;
use std::io::Write; // Synchronous write for settings.json if we use std::fs, but we can use tokio if needed.
// However, the prompt implies "Step A: Config Injection... Step B: Execution".
// Since launch_game is likely async (as it was), we should keep it async or make it sync if `Task::perform` wraps it.
// The previous signature was `async fn`. The prompt asks for `pub fn launch_game(...) -> Result<(), String>`.
// If it returns Result directly, it might be blocking. But we are in an async context (Iced).
// If I make it blocking, I should run it in `spawn_blocking`.
// However, `std::process::Command::spawn` is non-blocking effectively (it starts the process).
// `fs::write` is blocking.
// Given the requirements "Use std::process::Command", I will use `std::fs` for writing settings too for simplicity,
// assuming this runs in a thread or is fast enough.
// BUT, to be safe and "Senior Rust Architect", I should probably make it async or wrap blocking ops.
// The prompt signature `pub fn launch_game(config: &LauncherConfig) -> Result<(), String>` doesn't have `async`.
// If it's not async, I should use `std`.

use crate::core::config::LauncherConfig;

#[cfg(target_os = "windows")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO.exe";

#[cfg(target_os = "macos")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO";

#[cfg(target_os = "linux")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO";

pub fn launch_game(config: &LauncherConfig) -> Result<(), String> {
    // Step A: Config Injection
    inject_settings(config)?;

    // Step B: Execution
    let executable_path = config.install_path.join(ENGINE_EXECUTABLE_NAME);

    if !executable_path.exists() {
        return Err(format!("Engine binary not found at {:?}", executable_path));
    }

    // CRITICAL: Ensure chmod +x on Unix
    #[cfg(any(target_os = "linux", target_os = "macos"))]
    {
        use std::os::unix::fs::PermissionsExt;
        let metadata = std::fs::metadata(&executable_path)
            .map_err(|e| format!("Failed to get metadata: {}", e))?;
        let mut perms = metadata.permissions();
        perms.set_mode(0o755);
        std::fs::set_permissions(&executable_path, perms)
            .map_err(|e| format!("Failed to set permissions: {}", e))?;
    }

    let mut command = std::process::Command::new(&executable_path);
    command.current_dir(&config.install_path);

    // Step C: Detach
    // spawn() starts the process. By not calling wait(), we detach it.
    match command.spawn() {
        Ok(_) => Ok(()),
        Err(e) => Err(format!("Failed to spawn game process: {}", e)),
    }
}

fn inject_settings(config: &LauncherConfig) -> Result<(), String> {
    let settings_path = config.install_path.join("settings.json");

    // Populate with paths and Shard IP/Port
    let settings_json = json!({
        "ip": config.last_server_ip,
        "port": config.last_server_port,
        "ultimaonlinedirectory": config.install_path.to_string_lossy(),
        // We use install_path as the data directory as per context.
        // Assuming the ClassicUO structure is self-contained or data is in the root.

        // Add other necessary fields if known, or minimal set.
        "client_version": config.client_version,

        // Ensure defaults for others to avoid crashes
        "username": "",
        "password": "",
        "last_character_name": "",
        "last_server_name": "",
        "fps": 60,
        "window_size": [1024, 768],
        "window_position": [100, 100],
        "is_window_maximized": false,
        "sound_volume": 100,
        "music_volume": 50
    });

    let content = serde_json::to_string_pretty(&settings_json)
        .map_err(|e| format!("Failed to serialize settings: {}", e))?;

    std::fs::write(&settings_path, content)
        .map_err(|e| format!("Failed to write settings.json: {}", e))?;

    Ok(())
}
