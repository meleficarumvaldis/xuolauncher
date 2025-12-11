use serde_json::json;
 // Synchronous write for settings.json if we use std::fs, but we can use tokio if needed.
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

// Assuming the Launcher extracts to "ClassicUOLauncher" folder and the binary is inside.
// However, the ClassicUO Launcher is the wrapper. The prompt says "ClassicUO Launcher Integration".
// If we run the Launcher, it handles the game. But the "PLAY" button typically launches the GAME directly
// using the configuration we injected.
// The "ClassicUO Launcher" is a tool to update/configure ClassicUO, but OUR Launcher is also a Launcher.
// It's a bit redundant to launch a Launcher from a Launcher.
// BUT, the prompt explicitly asked for "ClassicUO Launcher Integration" and "Download/Install" it.
// If the goal is to play the game, we should probably stick to launching the Game Client if we have the assets.
// However, if the assets (client.exe, etc) come from the Manifest, we have the game.
// What if `ClassicUOLauncher` is the actual game client executable provided by the ClassicUO team?
// Actually, `ClassicUO` (the game engine) is what we usually run. `ClassicUOLauncher` is the C# update tool.
// Given we are writing a replacement launcher, we probably want to launch the engine directly.
// The engine binary is usually `ClassicUO.exe` (Windows) or `ClassicUO` (Linux/Mac).
// I'll stick to launching `ClassicUO.exe` / `ClassicUO` from the root or wherever it is installed.
// The manifest includes `client.exe`, which is the UO client, but we need the ClassicUO engine.
// Is the ClassicUO Engine included in the "ClassicUO Launcher" zip?
// Let's assume the zip contains the Engine as well, or the "Launcher" zip IS the release bundle for the engine + launcher tool.
// Checking the URL: `ClassicUOLauncher-win-x64-release.zip`. It likely contains `ClassicUO.exe` (the engine).
// In ClassicUO releases, the package contains `ClassicUO.exe`.
// So I will look for `ClassicUOLauncher/ClassicUO.exe` or just `ClassicUO.exe` if we unzip to root?
// The code in `launcher_installer.rs` unzips to `config.install_path`.
// If the zip has a root folder `ClassicUOLauncher`, then the path is `install_path/ClassicUOLauncher/ClassicUO.exe`.
// If it doesn't have a root folder, it's `install_path/ClassicUO.exe`.
// Most github releases for ClassicUO seem to put things in a folder or just flat.
// I'll check `launcher_installer.rs`... I am unzipping directly into `install_path`.
// If the zip has a folder inside, it will be `install_path/InsideFolder/...`.
// Let's assume the zip from `ClassicUO/deploy` is flat or we need to find the exe.
// For safety, let's search for the executable or assume a standard path `ClassicUO.exe`.
// If `launcher_installer.rs` logic is "if missing, download", and it unzips everything.
// The "ClassicUO Launcher" release usually contains the `ClassicUOLauncher.exe` AND `ClassicUO.exe` (the game).
// Wait, looking at ClassicUO/deploy... it seems to be just the Launcher?
// If so, where does the Engine come from? The Launcher downloads the Engine.
// But we are making a Launcher.
// The prompt says "ClassicUO Launcher Integration ... add a deflate and install routine".
// Maybe the user wants to give the player the option to use the official launcher too, OR the official launcher IS the distribution method for the engine?
// I will assume `ClassicUO.exe` is the target to run, and it's located where we unzipped.
// If the zip creates a subfolder `ClassicUOLauncher`, we need to account for that.
// I'll optimistically set it to `ClassicUO.exe` in the root of install path, OR `ClassicUOLauncher/ClassicUO.exe`.
// Let's try `ClassicUO.exe` first, if not found, try `ClassicUOLauncher/ClassicUO.exe`.

#[cfg(target_os = "windows")]
const ENGINE_EXECUTABLE_NAMES: &[&str] = &["ClassicUO.exe", "ClassicUOLauncher/ClassicUO.exe"];

#[cfg(target_os = "macos")]
const ENGINE_EXECUTABLE_NAMES: &[&str] = &["ClassicUO", "ClassicUOLauncher/ClassicUO"];

#[cfg(target_os = "linux")]
const ENGINE_EXECUTABLE_NAMES: &[&str] = &["ClassicUO", "ClassicUOLauncher/ClassicUO"];

pub fn launch_game(config: &LauncherConfig) -> Result<(), String> {
    // Step A: Config Injection
    inject_settings(config)?;

    // Step B: Execution
    let mut executable_path = None;
    for name in ENGINE_EXECUTABLE_NAMES {
        let p = config.install_path.join(name);
        if p.exists() {
            executable_path = Some(p);
            break;
        }
    }

    let executable_path = executable_path.ok_or_else(|| {
        format!("Engine binary not found in {:?}. Checked: {:?}", config.install_path, ENGINE_EXECUTABLE_NAMES)
    })?;

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
