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
pub async fn check_and_apply_self_update(_version_url: &str) -> Result<(), String> {
    println!("Self-update is deactivated for testing.");
    Ok(())
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
    // Self-update cleanup deactivated for testing.
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
