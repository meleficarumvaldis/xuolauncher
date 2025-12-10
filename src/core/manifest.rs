use serde::{Deserialize, Serialize};
use std::collections::HashMap;

#[derive(Debug, Serialize, Deserialize, Clone, PartialEq, Eq)]
pub enum AssetSource {
    Official,
    Custom,
}

#[derive(Debug, Serialize, Deserialize, Clone, PartialEq)]
pub struct Asset {
    pub path: String,          // Relative path (e.g., "art.mul")
    pub hash: String,          // SHA256 hex string
    pub size: u64,             // File size in bytes
    pub source: AssetSource,
    pub url: String,           // Remote URL for download
}

#[derive(Debug, Serialize, Deserialize, Clone, Default)]
pub struct Manifest {
    pub assets: Vec<Asset>,
}

impl Manifest {
    pub fn new() -> Self {
        Self { assets: Vec::new() }
    }

    /// Merges another manifest into this one.
    /// Assets with the same path in the overlay manifest will replace assets in this manifest.
    pub fn merge(&mut self, overlay: Manifest) {
        // Use a HashMap for efficient lookup and replacement by path
        let mut asset_map: HashMap<String, Asset> = self
            .assets
            .drain(..)
            .map(|a| (a.path.clone(), a))
            .collect();

        for asset in overlay.assets {
            // Insert or update. If the key exists, it's overwritten (overlay behavior).
            asset_map.insert(asset.path.clone(), asset);
        }

        // Rebuild the assets vector
        self.assets = asset_map.into_values().collect();
        // Optional: Sort by path for consistent order
        self.assets.sort_by(|a, b| a.path.cmp(&b.path));
    }
}
