if [ $# -eq 0 ]; then
    rm -rf build
    mkdir build
    cmake -S . -B build
    cmake --build build
elif [ $1 = debug ]; then
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
fi
