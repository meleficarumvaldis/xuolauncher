# XUO Launcher (Rust Edition)

Ein moderner, plattformübergreifender Launcher für Ultima Online Shards, geschrieben in Rust.

## Beschreibung

Dieser Launcher wurde entwickelt, um Spielern ein reibungsloses Erlebnis beim Installieren, Aktualisieren und Starten von Ultima Online zu bieten. Er nutzt moderne Technologien, um eine schnelle und zuverlässige Handhabung von Spieldateien zu gewährleisten.

## Funktionen

*   **Auto-Patching:** Automatische Überprüfung und Aktualisierung von Spieldateien (Hash-basiert).
*   **Config-Injection:** Automatische Konfiguration von `settings.json` für ClassicUO (IP, Port, Pfade).
*   **Cross-Platform:** Unterstützt Windows, Linux und macOS.
*   **Modernes UI:** Dunkles "Mystic Fantasy" Design mit intuitiver Bedienung.
*   **Launcher-Only:** Kein C# oder Legacy-Code, reiner Rust-Stack.

## Installation & Build

Um den Launcher aus dem Quellcode zu kompilieren, wird Rust benötigt.

### Voraussetzungen

1.  **Rust installieren:** [rustup.rs](https://rustup.rs/)
2.  **Abhängigkeiten (Linux):**
    ```bash
    sudo apt update
    sudo apt install build-essential libssl-dev pkg-config
    ```

### Kompilieren und Starten

```bash
git clone <repository-url>
cd xuolauncher
cargo run --release
```

## Projektstruktur

Die Struktur folgt strikten Modularitätsrichtlinien:

*   `src/core/`: Kernlogik (Konfiguration, Status, Installation, Launcher-Logik).
    *   `launcher.rs`: Startlogik und Prozessverwaltung.
    *   `installer.rs`: Pfadverwaltung und Erstinstallation.
*   `src/gui/`: Benutzeroberfläche (Iced).
    *   `screens/`: Einzelne Ansichten (Dashboard, Patcher).
    *   `theme.rs`: Visuelles Design (Farben, Abstände).
*   `src/net/`: Netzwerkkommunikation (Download, API).

## Lizenz

MIT
