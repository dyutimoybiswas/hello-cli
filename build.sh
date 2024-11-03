if [ $# -eq 0 ]; then
    rm -rf build
    mkdir build
    cd build
    cmake ..
    make
elif [ $1 = debug ]; then
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
fi
