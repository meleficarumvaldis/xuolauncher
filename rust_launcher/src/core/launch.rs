use serde_json::json;
use tokio::io::AsyncWriteExt;
use crate::core::config::LauncherConfig;

#[cfg(target_os = "windows")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO.exe";

#[cfg(target_os = "macos")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO";

#[cfg(target_os = "linux")]
const ENGINE_EXECUTABLE_NAME: &str = "ClassicUO";


pub async fn inject_settings(config: &LauncherConfig) -> Result<(), String> {
    let settings_path = config.install_path.join("settings.json");

    // Construct the ClassicUO settings JSON
    // We strictly enforce Server IP, Port, and Client Version as per requirements.
    // In a real app, we might want to read existing settings and merge,
    // but the requirement says "generate/overwrite".

    // Note: ClassicUO settings.json structure can be complex.
    // This is a simplified example based on common fields.
    let settings_json = json!({
        "ip": config.last_server_ip,
        "port": config.last_server_port,
        "client_version": config.client_version,
        "ultimaonlinedirectory": config.install_path.to_string_lossy(),
        // Add other default settings here
        "username": "",
        "password": "",
        "last_character_name": ""
    });

    let content = serde_json::to_string_pretty(&settings_json)
        .map_err(|e| format!("Failed to serialize settings: {}", e))?;

    let mut file = tokio::fs::File::create(&settings_path).await
        .map_err(|e| format!("Failed to create settings.json: {}", e))?;

    file.write_all(content.as_bytes()).await
        .map_err(|e| format!("Failed to write settings.json: {}", e))?;

    Ok(())
}

pub async fn launch_game(config: &LauncherConfig) -> Result<(), String> {
    let executable_path = config.install_path.join(ENGINE_EXECUTABLE_NAME);

    if !executable_path.exists() {
        return Err(format!("Engine binary not found at {:?}", executable_path));
    }

    // Ensure permissions on Unix-like systems
    #[cfg(any(target_os = "linux", target_os = "macos"))]
    {
        use std::os::unix::fs::PermissionsExt;
        let mut perms = tokio::fs::metadata(&executable_path).await
            .map_err(|e| format!("Failed to get metadata: {}", e))?
            .permissions();
        perms.set_mode(0o755);
        tokio::fs::set_permissions(&executable_path, perms).await
            .map_err(|e| format!("Failed to set permissions: {}", e))?;
    }

    // Spawn the process
    // We use std::process::Command here because we might want to detach it
    // effectively. Tokio's Command is also fine but std is explicitly mentioned
    // in requirements for Command (though not strictly exclusive).
    // Let's use Tokio's Command for async consistency, or std if we want to detach easily.
    // Requirement says "Detach if necessary".

    let mut command = std::process::Command::new(executable_path);
    command.current_dir(&config.install_path);

    // Detach by spawning and dropping the child handle (not waiting on it)
    match command.spawn() {
        Ok(_) => Ok(()),
        Err(e) => Err(format!("Failed to spawn game process: {}", e)),
    }
}
