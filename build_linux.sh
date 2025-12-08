#!/bin/bash

# Build script for Linux
# Ensures dependencies are checked (basic check) and runs qmake/make

set -e

# Function to check for commands
command_exists () {
    type "$1" &> /dev/null ;
}

echo "Starting build process for Linux..."

# Check for qmake (qt6)
QMAKE="qmake"
if command_exists qmake6 ; then
    QMAKE="qmake6"
elif command_exists qmake-qt5 ; then
    QMAKE="qmake-qt5"
fi

if ! command_exists $QMAKE ; then
    echo "Error: qmake not found. Please install Qt development tools (Qt5 or Qt6)."
    exit 1
fi

echo "Using qmake: $QMAKE"

# Check for make
if ! command_exists make ; then
    echo "Error: make not found. Please install build-essential or equivalent."
    exit 1
fi

# Create build directory
BUILD_DIR="build_linux"
if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning previous build..."
    rm -rf "$BUILD_DIR"
fi
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

# Run qmake
echo "Running qmake..."
$QMAKE ../xuo.pro

# Run make
echo "Running make..."
make -j$(nproc)

echo "Build complete!"
echo "Executables can be found in:"
echo "  - $BUILD_DIR/src/launcher/xuolauncher"
echo "  - $BUILD_DIR/src/manager/xuomanager"
