# Ensure mingw-w64-gcc cross-compiler and wine package are installed to generate .exe
if [ $# -eq 0 ]; then
    rm -rf build
    mkdir build
    cmake -S . -B build
    cmake --build build
elif [ $1 = Windows ]; then
    rm -rf build-windows/
    cmake -DCMAKE_TOOLCHAIN_FILE=windows-toolchain.cmake -B build-windows
    cmake --build build-windows --config Release
fi
