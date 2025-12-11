use crate::core::manifest::{Asset, Manifest};
use sha2::{Digest, Sha256};
use std::fs::File;
use std::io::{Read, BufReader};
use std::path::Path;
use tokio::task;
use futures::StreamExt;

pub async fn verify_files(base_path: &Path, manifest: &Manifest) -> Vec<Asset> {
    let base_path = base_path.to_owned();
    let assets = manifest.assets.clone();

    let tasks = futures::stream::iter(assets.into_iter().map(move |asset| {
        let path = base_path.join(&asset.path);
        let expected_hash = asset.hash.clone();

        async move {
            let needs_update = task::spawn_blocking(move || {
                should_update_file(&path, &expected_hash)
            }).await.unwrap_or(true);

            if needs_update {
                Some(asset)
            } else {
                None
            }
        }
    }));

    let results: Vec<Option<Asset>> = tasks.buffer_unordered(16).collect().await;
    results.into_iter().filter_map(|x| x).collect()
}

fn should_update_file(path: &Path, expected_hash: &str) -> bool {
    if !path.exists() {
        return true;
    }
    match calculate_sha256(path) {
        Ok(local_hash) => local_hash != expected_hash,
        Err(_) => true,
    }
}

fn calculate_sha256(path: &Path) -> std::io::Result<String> {
    let file = File::open(path)?;
    let mut reader = BufReader::new(file);
    let mut hasher = Sha256::new();
    let mut buffer = [0; 32 * 1024];

    loop {
        let count = reader.read(&mut buffer)?;
        if count == 0 {
            break;
        }
        hasher.update(&buffer[..count]);
    }

    let result = hasher.finalize();
    Ok(hex::encode(result))
}