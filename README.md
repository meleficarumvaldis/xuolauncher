# X:UO Launcher & Manager

Dieses Repository enthält den Launcher und Manager für CrossUO. Das Projekt wurde modernisiert und modularisiert, um die Wartbarkeit und Weiterentwicklung zu erleichtern.

## Projektstruktur

Das Projekt ist nun modular aufgebaut und befindet sich im `src/` Verzeichnis:

*   `src/launcher`: Der Quellcode für die Launcher-Anwendung (`xuolauncher`).
*   `src/manager`: Der Quellcode für die Manager-Anwendung (`xuomanager`).
*   `src/common`: Gemeinsam genutzter Code und Ressourcen (Updater, Icons, etc.).

## Voraussetzungen

Um das Projekt zu kompilieren, benötigen Sie:

*   **Qt 5.15** oder **Qt 6.x** (Qt 6 wird empfohlen).
*   Ein C++17 kompatibler Compiler (GCC, Clang, MSVC).
*   `qmake` oder `cmake` (aktuell werden `.pro` Dateien für qmake verwendet).

### Abhängigkeiten (Linux - Debian/Ubuntu)

Für Qt 6:
```bash
sudo apt-get install qt6-base-dev qt6-base-dev-tools build-essential
```

Für Qt 5:
```bash
sudo apt-get install qtbase5-dev qtbase5-dev-tools build-essential
```

## Kompilieren

Das Projekt verwendet ein `subdirs` Template, um beide Anwendungen gleichzeitig zu bauen.

1.  Erstellen Sie ein Build-Verzeichnis:
    ```bash
    mkdir build
    cd build
    ```

2.  Führen Sie `qmake` aus (verwenden Sie `qmake6` für Qt 6 oder `qmake` für Qt 5):
    ```bash
    qmake6 ../xuo.pro
    # oder
    qmake ../xuo.pro
    ```

3.  Kompilieren Sie das Projekt:
    ```bash
    make -j$(nproc)
    ```

Nach dem erfolgreichen Kompilieren finden Sie die ausführbaren Dateien in den Unterverzeichnissen `src/launcher/` und `src/manager/` innerhalb des Build-Verzeichnisses.

## Entwicklung

### Modulübersicht

*   **Launcher (`src/launcher`)**:
    *   Verantwortlich für das Starten des Spiels, Verwalten von Serverprofilen und Proxys.
    *   Hauptklasse: `LauncherWindow`.
*   **Manager (`src/manager`)**:
    *   Verwaltet Updates und Pakete für das Spiel.
    *   Hauptklasse: `ManagerWindow`.
*   **Common (`src/common`)**:
    *   Enthält den `UpdateManager` und Hashing-Funktionen (`xxhash`), die von beiden Anwendungen genutzt werden.

### Hinzufügen neuer Dateien

Wenn Sie neue Quelldateien hinzufügen, stellen Sie sicher, dass sie in der entsprechenden `.pro` Datei (`src/launcher/launcher.pro` oder `src/manager/manager.pro`) registriert werden. Gemeinsamer Code sollte in `src/common` abgelegt und in `src/common/common.pri` (falls erstellt) oder direkt in den `.pro` Dateien referenziert werden.

## Lizenz

Siehe [LICENSE](LICENSE) Datei für Details.
