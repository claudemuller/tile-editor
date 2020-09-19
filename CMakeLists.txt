cmake_minimum_required(VERSION 3.17)
project(tile-editor)

set(CMAKE_CXX_STANDARD 14)

# Adds the files that are part of the project
add_executable(tile-editor src/main.cpp src/Constants.h
        )

# Tells CMake that the find scripts are inside inside subfolder /cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${tile-editor_SOURCE_DIR}/cmake")

# Asks CMake to find the SDL libraries in our system
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Asks CMake to include the library folders during build
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

# Asks CMake to link against the libraries during build
target_link_libraries(tile-editor
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
