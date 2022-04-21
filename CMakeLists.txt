cmake_minimum_required(VERSION 3.23.0)
project(Minecraft)

include(ExternalProject) 
ExternalProject_Add(
    OgreProject
    GIT_REPOSITORY https://github.com/OGRECave/ogre.git
 )
include_directories( #Code include directories
    Code/Headers
    Code
)

set( #Ogre include files
    OgreFiles
)


set( #Code include cpp files
    CodeFiles
    Code/Debug.cpp
    Code/World.cpp
    Code/GraphicsMain.cpp
    Code/WorldGeneration.cpp
)

include_directories( #includes include directory
    Includes/Ogre/OgreHeaders
    Includes/Ogre/OgreSource
    Includes/Nlohmann
)

add_executable(${PROJECT_NAME} ${CodeFiles} ${OgreFiles})