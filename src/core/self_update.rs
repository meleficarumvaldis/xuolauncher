use std::env;
use std::fs;
use std::path::Path;
use std::process::Command;
#[cfg(unix)]
use std::os::unix::fs::PermissionsExt;
use std::io::Write;
use serde::Deserialize;

#[derive(Deserialize, Debug)]
pub struct RemoteVersion {
    version: String,
    url: String,
}

/// Checks for updates and applies them if a newer version is available.
/// This function will exit the process if an update is successfully applied.
pub async fn check_and_apply_self_update(version_url: &str) -> Result<(), String> {
    let current_version = env!("CARGO_PKG_VERSION");
    println!("Current version: {}", current_version);

    let client = reqwest::Client::new();
    let remote_info: RemoteVersion = client.get(version_url)
        .send()
        .await.map_err(|e| format!("Failed to check update: {}", e))?
        .json()
        .await.map_err(|e| format!("Failed to parse version info: {}", e))?;

    if !is_newer(&remote_info.version, current_version) {
        println!("No update available (remote: {}).", remote_info.version);
        return Ok(());
    }

    println!("New version {} found. Downloading...", remote_info.version);

    let current_exe = env::current_exe().map_err(|e| format!("Failed to get current exe path: {}", e))?;
    let exe_dir = current_exe.parent().ok_or("Failed to get exe directory")?;
    let tmp_path = exe_dir.join("launcher.tmp");

    let response = client.get(&remote_info.url)
        .send()
        .await.map_err(|e| format!("Failed to download update: {}", e))?;
    let bytes = response.bytes().await.map_err(|e| format!("Failed to read bytes: {}", e))?;

    {
        let mut file = fs::File::create(&tmp_path).map_err(|e| format!("Failed to create tmp file: {}", e))?;
        file.write_all(&bytes).map_err(|e| format!("Failed to write bytes: {}", e))?;
    }

    #[cfg(unix)]
    {
        let mut perms = fs::metadata(&tmp_path).map_err(|e| e.to_string())?.permissions();
        perms.set_mode(0o755);
        fs::set_permissions(&tmp_path, perms).map_err(|e| e.to_string())?;
    }

    println!("Applying update...");
    apply_update(&current_exe, &tmp_path)
}

fn is_newer(remote: &str, current: &str) -> bool {
    let parse = |v: &str| -> Vec<u32> {
        v.split('.')
         .map(|s| s.parse().unwrap_or(0))
         .collect()
    };
    let r_parts = parse(remote);
    let c_parts = parse(current);

    for (r, c) in r_parts.iter().zip(c_parts.iter()) {
        if r > c { return true; }
        if r < c { return false; }
    }
    r_parts.len() > c_parts.len()
}

pub fn cleanup_old_binary() {
    if let Ok(current_exe) = env::current_exe() {
        // On Windows, we renamed to .old. On Unix, the old file was replaced/unlinked automatically by rename.
        // However, if we want to support the Windows strategy specifically:
        #[cfg(target_os = "windows")]
        {
            let old_exe = current_exe.with_extension("old");
            if old_exe.exists() {
                let _ = fs::remove_file(old_exe);
            }
        }
        #[cfg(not(target_os = "windows"))]
        {
             // Suppress unused variable warning on non-windows
             let _ = current_exe;
        }
    }
}

#[cfg(target_os = "windows")]
fn apply_update(current: &Path, new: &Path) -> Result<(), String> {
    let old = current.with_extension("old");
    if old.exists() {
        fs::remove_file(&old).map_err(|e| format!("Failed to remove existing old binary: {}", e))?;
    }
    fs::rename(current, &old).map_err(|e| format!("Failed to rename current to old: {}", e))?;
    fs::rename(new, current).map_err(|e| format!("Failed to rename new to current: {}", e))?;

    Command::new(current)
        .spawn()
        .map_err(|e| format!("Failed to spawn new process: {}", e))?;

    std::process::exit(0);
}

#[cfg(not(target_os = "windows"))]
fn apply_update(current: &Path, new: &Path) -> Result<(), String> {
    fs::rename(new, current).map_err(|e| format!("Failed to replace binary: {}", e))?;

    Command::new(current)
        .spawn()
        .map_err(|e| format!("Failed to spawn new process: {}", e))?;

    std::process::exit(0);
}
