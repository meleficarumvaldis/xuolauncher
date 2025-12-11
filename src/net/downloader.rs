use crate::core::manifest::Asset;
use crate::core::message::Message;
use futures::StreamExt;
use std::path::PathBuf;
use tokio::fs::File;
use tokio::io::AsyncWriteExt;

pub fn download_assets(
    assets: Vec<Asset>,
    base_path: PathBuf,
) -> impl futures::Stream<Item = Message> {
    let (tx, rx) = futures::channel::mpsc::channel(32);

    tokio::spawn(async move {
        let tx = tx;
        let mut stream = futures::stream::iter(assets)
            .map(|asset| {
                let base = base_path.clone();
                let mut tx_inner = tx.clone();
                let asset_clone = asset.clone();
                async move {
                    let path = base.join(&asset_clone.path);
                    match download_single_file(asset_clone.clone(), path, &mut tx_inner).await {
                        Ok(_) => Ok(asset_clone),
                        Err(e) => Err(e),
                    }
                }
            })
            .buffer_unordered(3);

        while let Some(result) = stream.next().await {
             match result {
                 Ok(asset) => {
                     let mut tx = tx.clone();
                     use futures::SinkExt;
                     let _ = tx.feed(Message::FileDownloaded(asset)).await;
                 }
                 Err(e) => {
                     let mut tx = tx.clone();
                     use futures::SinkExt;
                     let _ = tx.start_send(Message::PatchError(format!("Download failed: {}", e)));
                     return;
                 }
             }
        }

        let mut tx = tx.clone();
        use futures::SinkExt;
        let _ = tx.start_send(Message::PatchComplete);
    });

    rx
}

async fn download_single_file(
    asset: Asset,
    path: PathBuf,
    tx: &mut futures::channel::mpsc::Sender<Message>,
) -> Result<u64, String> {
    if let Some(parent) = path.parent() {
        tokio::fs::create_dir_all(parent).await.map_err(|e| e.to_string())?;
    }

    let client = reqwest::Client::new();
    let res = client.get(&asset.url).send().await.map_err(|e| e.to_string())?;

    if !res.status().is_success() {
        return Err(format!("HTTP Error: {}", res.status()));
    }

    let total_size = res.content_length().unwrap_or(asset.size);
    let mut stream = res.bytes_stream();
    let mut file = File::create(&path).await.map_err(|e| e.to_string())?;
    let mut downloaded: u64 = 0;
    let mut last_update = std::time::Instant::now();

    while let Some(item) = stream.next().await {
        let chunk = item.map_err(|e| e.to_string())?;
        file.write_all(&chunk).await.map_err(|e| e.to_string())?;
        downloaded += chunk.len() as u64;

        if last_update.elapsed().as_millis() > 50 {
             use futures::SinkExt;
             let _ = tx.feed(Message::DownloadProgress {
                file: asset.path.clone(),
                downloaded,
                total: total_size,
            }).await;
            last_update = std::time::Instant::now();
        }
    }
    // Flush to ensure last progress is sent or just continue
    let _ = tx.flush().await;
    Ok(downloaded)
}