# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Project name and version
# Update version after publishing new release
project(hello-cli VERSION 1.2.3)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add extra debug flags for the Debug configuration (compiler-specific)
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W4")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -pedantic -Weffc++")
endif()

# Add the include directory for header files
include_directories(inc)

# Set the source files
file(GLOB LIB_SOURCES "src/display.cpp" "src/inputhandler.cpp" "src/operations.cpp")
add_library(hello-cli-lib ${LIB_SOURCES})
target_include_directories(hello-cli-lib PUBLIC inc)

# Create the executable
add_executable(hello-cli src/main.cpp)
target_link_libraries(hello-cli PRIVATE hello-cli-lib)

# Specify include directories for the target
target_include_directories(hello-cli PUBLIC inc)

# Testing
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
