# Ensure mingw-w64-gcc cross-compiler and wine package are installed to generate .exe

case $1 in
  Windows)
    echo "Building Windows executable..."
    rm -rf build-windows/
    cmake -DCMAKE_TOOLCHAIN_FILE=windows-toolchain.cmake -B build-windows
    cmake --build build-windows --config Release
    ;;

  macOS)
    echo "Building macOS executable..."
    rm -rf build-macos/
    cmake -DCMAKE_SYSTEM_NAME=Darwin -B build-macos
    cmake --build build-macos --config Release
    ;;

  *)
    echo "Building Linux executable..."
    rm -rf build/
    cmake -S . -B build
    cmake --build build --config Release
    ;;
esac
