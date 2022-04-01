# mine-C-raft
A minecraft replica in c++ (Currently useless)

If you are on **Linux** run `Setup.sh`, it will configure everything for you, then execute the `Minecraft` file in the `build` directory

If you are on **Windows**:
1. First install the dependencies (use the inbedded links)

    - [g++](https://osdn.net/projects/mingw) : Once downloaded, execute the installer. When finished, a window should pop up, check `mingw32-base-bin` and `mingw32-gcc-g++-bin` and on the top left corner select `Installation -> Apply Changes`

    - [Ogre3d](https://www.ogre3d.org/download/sdk/sdk-ogre) : Click on `MSVC SDK`, extract the zip file and move all of the contents to `C:\MinGW`

    - [Nlohmann json](https://github.com/nlohmann/json) : Click on `Code` and `Download zip`, extract the zip file and copy the `include` folder to `C:\MinGW`

    - [Cmake](https://cmake.org/download) : Scroll down, download the `Windows x64 Installer` and install it

    - [Visual Studio](https://visualstudio.microsoft.com/downloads) : Select `Download Visual Studio -> Community` and execute the installer. A window will pop up, check `Desktop development with C++` and `Game development with C++`, hit install

2. In windows search and open `Edit the system environment variables`, click `Environment Variables` in the bottom of the window. Then in the top half of the window select `Path` and click `Edit`, click `New` and type `C:\MinGW\bin`, click Ok in every window to save and close

3. Open `Cmake` and set the source code path to the root folder of the project where CMakeLists.txt is, select any folder you want except the root folder to build the binaries

4. Click `Configure` and for the generator choose the version of Visual Studio you have installed, click finish and then `Generate`

5. Select open project in Cmake and it will take you to Visual Studio, there make sure you have selected `Release` in the top, right click `ALL_BUILD` and select `build`

6. After that there will be an executable at the `Release` folder in the build directory that you decided