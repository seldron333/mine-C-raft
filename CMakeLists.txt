cmake_minimum_required(VERSION 3.23.0)
project(Minecraft)

include_directories( #Code include directories
    Code
    Code/Headers
)

set( #Code include cpp files
    CodeFiles
    Code/Debug.cpp
    Code/World.cpp
    Code/GraphicsMain.cpp
    Code/WorldGeneration.cpp
)

include_directories( #includes include directory
    Includes
    Includes/include
    Includes/include/OGRE
    Includes/include/OGRE/Bites
    Includes/include/OGRE/Overlay
    Includes/include/OGRE/RTShaderSystem
    Includes/include/OGRE/Threading
)

link_directories(
    Includes/lib/
)

link_libraries(
    libOgreBites.so
    libOgreMain.so
    libOgreMeshLodGenerator.so
    libOgreOverlay.so
    libOgrePaging.so
    libOgreProperty.so
    libOgreRTShaderSystem.so
    libOgreTerrain.so
    libOgreVolume.so
)

add_executable(
    ${PROJECT_NAME} 
    ${CodeFiles}
)