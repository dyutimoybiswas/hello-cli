if [ $1 = debug ]; then
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
else
    rm -rf build
    mkdir build
    cd build
    cmake ..
    make
fi
