#!/bin/bash
set -e

# Detect the current OS
detect_os() {
  case "$(uname -s)" in
    Darwin)
      echo "macOS"
      ;;
    Linux)
      echo "Linux"
      ;;
    MINGW*|MSYS*|CYGWIN*|Windows_NT)
      echo "Windows"
      ;;
    *)
      echo "Unknown"
      ;;
  esac
}

OS="${1:-$(detect_os)}"

case "$OS" in
  Windows)
    echo "Building for Windows..."
    cmake -S . -B build-windows -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build build-windows --config Release
    echo "Output: build-windows/hello-cli.exe"
    ;;

  macOS)
    echo "Building for macOS..."
    cmake -S . -B build-macos -DCMAKE_BUILD_TYPE=Release
    cmake --build build-macos --config Release
    echo "Output: build-macos/hello-cli"
    ;;

  Linux)
    echo "Building for Linux..."
    cmake -S . -B build-linux -DCMAKE_BUILD_TYPE=Release
    cmake --build build-linux --config Release
    echo "Output: build-linux/hello-cli"
    ;;

  *)
    echo "Error: Unsupported OS '$OS'"
    echo "Usage: $0 [Windows|macOS|Linux]"
    exit 1
    ;;
esac
