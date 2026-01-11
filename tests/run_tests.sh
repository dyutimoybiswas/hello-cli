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

OS="$(detect_os)"
BUILD_DIR="build-${OS}"

if [ "$OS" = "unknown" ]; then
  echo "Error: Unsupported OS"
  exit 1
fi

echo "Building tests for ${OS} in ${BUILD_DIR}..."
cmake -S .. -B ${BUILD_DIR}
cmake --build ${BUILD_DIR}

echo "Running tests..."
if [ "$OS" = "windows" ]; then
  ./${BUILD_DIR}/tests/hello-cli-tests.exe
else
  ./${BUILD_DIR}/tests/hello-cli-tests
fi
