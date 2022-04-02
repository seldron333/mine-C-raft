cmake_minimum_required(VERSION 3.23.0)
project(Minecraft)

include_directories( #Local include directories
Code/Headers
Code
)

set( #local include cpp files
    SourceFiles
    Code/Debug.cpp
    Code/World.cpp
    Code/GraphicsMain.cpp
    Code/GraphicsWorldGeneration.cpp
)

add_executable(${PROJECT_NAME} ${SourceFiles})

if(UNIX)
    set(locI /usr/local/include)
    set(locL /usr/local/lib)
    set(usrI /usr/include)
    include_directories( #Ogre includes
        ${locI}/OGRE
        ${locI}/OGRE/Bites
        ${locI}/OGRE/RTShaderSystem
        ${locI}/OGRE/Overlay
    )
    include_directories( #Other includes
        ${usrI}/nlohmann
    )
    target_link_libraries( #Libraries
        Minecraft
        ${locL}/libOgreBites.so 
        ${locL}/libOgreMain.so
        ${locL}/libOgreRTShaderSystem.so
    )
endif(UNIX)


if(WIN32) #Same but windows
    set(incl C:/MinGW/include)
    set(libs C:/MinGW/lib)
    set(bin C:/MinGW/bin)
    include_directories(
        ${incl}/OGRE
        ${incl}/OGRE/Bites
        ${incl}/OGRE/RTShaderSystem
        ${incl}/OGRE/Overlay
    )
    include_directories(
        ${incl}/nlohmann
    )
    target_link_libraries(
        Minecraft
        ${libs}/OgreBites.lib 
        ${libs}/OgreMain.lib
        ${libs}/OgreRTShaderSystem.lib
    )
endif(WIN32)