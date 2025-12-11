use std::path::Path;
use std::fs;
use std::io;
use reqwest::Client;
use futures::StreamExt;
use tokio::io::AsyncWriteExt;
use zip::ZipArchive;

/// Downloads and installs the ClassicUO Launcher if not present.
pub async fn install_classicuo_launcher(install_path: &Path) -> Result<(), String> {
    let launcher_dir = install_path.join("ClassicUOLauncher");

    // We can assume if the directory exists and has some key file, it's installed.
    // Or we can just overwrite every time?
    // The requirement says "add a deflate and install routine", implying it should happen if missing or maybe always update?
    // Let's check if the executable exists.
    let exe_name = if cfg!(target_os = "windows") {
        "ClassicUOLauncher.exe"
    } else {
        "ClassicUOLauncher"
    };

    let exe_path = launcher_dir.join(exe_name);
    if exe_path.exists() {
        // Already installed.
        // NOTE: In a real scenario we might want to check version.
        // For now, we assume if it exists, we are good.
        return Ok(());
    }

    let url = get_launcher_url();
    let temp_zip = install_path.join("launcher_temp.zip");

    // Ensure install path exists
    if !install_path.exists() {
        tokio::fs::create_dir_all(install_path).await.map_err(|e| e.to_string())?;
    }

    // Download
    download_file(url, &temp_zip).await?;

    // Unzip
    // We use spawn_blocking because zip extraction is synchronous and CPU intensive.
    let install_path_clone = install_path.to_path_buf();
    let temp_zip_clone = temp_zip.clone();

    tokio::task::spawn_blocking(move || {
        unzip_file(&temp_zip_clone, &install_path_clone)
    }).await.map_err(|e| e.to_string())??;

    // Cleanup zip
    tokio::fs::remove_file(temp_zip).await.map_err(|e| e.to_string())?;

    Ok(())
}

fn get_launcher_url() -> &'static str {
    if cfg!(target_os = "windows") {
        "https://github.com/ClassicUO/deploy/releases/latest/download/ClassicUOLauncher-win-x64-release.zip"
    } else if cfg!(target_os = "macos") {
         "https://github.com/ClassicUO/deploy/releases/latest/download/ClassicUOLauncher-osx-x64-release.zip"
    } else {
         "https://github.com/ClassicUO/deploy/releases/latest/download/ClassicUOLauncher-linux-x64-release.zip"
    }
}

async fn download_file(url: &str, dest: &Path) -> Result<(), String> {
    let client = Client::new();
    let res = client.get(url).send().await.map_err(|e| e.to_string())?;

    if !res.status().is_success() {
        return Err(format!("Failed to download launcher: HTTP {}", res.status()));
    }

    let mut stream = res.bytes_stream();
    let mut file = tokio::fs::File::create(dest).await.map_err(|e| e.to_string())?;

    while let Some(item) = stream.next().await {
        let chunk = item.map_err(|e| e.to_string())?;
        file.write_all(&chunk).await.map_err(|e| e.to_string())?;
    }

    file.flush().await.map_err(|e| e.to_string())?;
    Ok(())
}

fn unzip_file(zip_path: &Path, dest_dir: &Path) -> Result<(), String> {
    let file = fs::File::open(zip_path).map_err(|e| e.to_string())?;
    let mut archive = ZipArchive::new(file).map_err(|e| e.to_string())?;

    for i in 0..archive.len() {
        let mut file = archive.by_index(i).map_err(|e| e.to_string())?;
        let outpath = match file.enclosed_name() {
            Some(path) => dest_dir.join(path),
            None => continue,
        };

        if file.name().ends_with('/') {
            fs::create_dir_all(&outpath).map_err(|e| e.to_string())?;
        } else {
            if let Some(p) = outpath.parent() {
                if !p.exists() {
                    fs::create_dir_all(p).map_err(|e| e.to_string())?;
                }
            }
            let mut outfile = fs::File::create(&outpath).map_err(|e| e.to_string())?;
            io::copy(&mut file, &mut outfile).map_err(|e| e.to_string())?;
        }

        // Set permissions on Unix
        #[cfg(unix)]
        {
            use std::os::unix::fs::PermissionsExt;
            if let Some(mode) = file.unix_mode() {
                fs::set_permissions(&outpath, fs::Permissions::from_mode(mode)).map_err(|e| e.to_string())?;
            }
        }
    }
    Ok(())
}
