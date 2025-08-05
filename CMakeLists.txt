# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(hello-cli VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add extra debug flags for the Debug configuration
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic -Weffc++")

# Add the include directory for header files
include_directories(inc)

# Set the source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(hello-cli ${SOURCES})
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set_target_properties(hello-cli PROPERTIES OUTPUT_NAME "hello-cli.exe")
endif()

# Specify include directories for the target
target_include_directories(hello-cli PUBLIC inc)
