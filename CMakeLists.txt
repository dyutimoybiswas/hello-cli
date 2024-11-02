# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(hello-cli VERSION 1.0)

# Add the include directory for header files
include_directories(inc)

# Set the source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(hello-cli ${SOURCES})

# Specify include directories for the target
target_include_directories(hello-cli PUBLIC inc)
