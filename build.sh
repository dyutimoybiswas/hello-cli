# Ensure mingw-w64-gcc cross-compiler and wine package are installed to generate .exe

case $1 in
  Windows)
    echo "Building Windows executable..."
    cmake -DCMAKE_SYSTEM_NAME=Windows -B build-windows
    cmake --build build-windows --config Release
    ;;

  macOS)
    echo "Building macOS executable..."
    cmake -DCMAKE_SYSTEM_NAME=Darwin -B build-macos
    cmake --build build-macos --config Release
    ;;

  *)
    echo "Building Linux executable..."
    cmake -S . -B build-linux
    cmake --build build-linux --config Release
    ;;
esac
