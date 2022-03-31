cmake_minimum_required(VERSION 3.0.0)
project(Minecraft)
add_executable(${PROJECT_NAME} Code/Graphics/GraphicsMain.cpp)


include_directories( #Local include directories
    Code/Headers 
    Code/Graphics
    Code
)

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
    if(MINGW)
        set(incl C:\\MinGW\\include)
        set(libs C:\\MinGW\\lib)
        include_directories(
            ${incl}\OGRE
            ${incl}\OGRE\Bites
            ${incl}\OGRE\RTShaderSystem
            ${incl}\OGRE\Overlay

            ${libs}\libOgreBites.so
            ${libs}\libOgreMain.so
            ${libs}\libOgreRTShaderSystem.so
        )
        include_directories(
            ${incl}\nlohmann
        )
        target_link_libraries(
            Minecraft
            ${locL}/libOgreBites.so 
            ${locL}/libOgreMain.so
            ${locL}/libOgreRTShaderSystem.so
        )
    endif(MINGW)
endif(WIN32)
