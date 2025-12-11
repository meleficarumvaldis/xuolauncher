use crate::core::manifest::{Asset, Manifest};
use sha2::{Digest, Sha256};
use std::fs::File;
use std::io::{Read, BufReader};
use std::path::Path;
use tokio::task;

/// Verifies local files against the manifest.
/// Returns a list of assets that need to be updated (missing or hash mismatch).
pub async fn verify_files(base_path: &Path, manifest: &Manifest) -> Vec<Asset> {
    let mut files_to_update = Vec::new();
    let base_path = base_path.to_owned();
    let assets = manifest.assets.clone();

    // We can run verification in parallel chunks or one by one.
    // Since it's IO bound and CPU bound (hashing), tokio::spawn_blocking is good.
    // However, spawning thousands of tasks might be too much.
    // Let's use a stream or just iterate for now, but ensure hashing is off the main thread.

    // For a cleaner implementation, we'll verify each file.
    // Ideally we would use something like `futures::stream::iter` with `buffer_unordered`.

    // NOTE: The prompt says "Compare local hashes vs. Manifest hashes to generate a Vec<Asset> of missing/outdated files."
    // And "Performance: Do not block the UI thread! Use tokio::fs or tokio::task::spawn_blocking for hashing large files."

    for asset in assets {
        let path = base_path.join(&asset.path);
        let expected_hash = asset.hash.clone();

        let needs_update = task::spawn_blocking(move || {
            should_update_file(&path, &expected_hash)
        }).await.unwrap_or(true); // If task fails (panic), assume update needed.

        if needs_update {
            files_to_update.push(asset);
        }
    }

    files_to_update
}

/// Checks if a file needs updating by comparing SHA256 hash.
fn should_update_file(path: &Path, expected_hash: &str) -> bool {
    if !path.exists() {
        return true;
    }

    match calculate_sha256(path) {
        Ok(local_hash) => local_hash != expected_hash,
        Err(_) => true, // If we can't read the file, re-download it.
    }
}

fn calculate_sha256(path: &Path) -> std::io::Result<String> {
    let file = File::open(path)?;
    let mut reader = BufReader::new(file);
    let mut hasher = Sha256::new();
    let mut buffer = [0; 8192];

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
