# mine-C-raft
A minecraft replica in c++ (Currently useless)

If you are on ```Linux``` run ```Setup.sh``` and  it will configure everything for you, then execute the ```Minecraft``` file in the build directory

If you are on ```Windows```:
1. First install the ```dependencies```
2. Open ```cmake``` and set the source code path to the root folder of the project where CMakeLists.txt is, select any folder you want except the root folder to build the binaries
3. Click ```Configure``` and for the generator choose the version of Visual Studio you have installed, click finish and then ```Generate```
4. Select open project in cmake and it will take you to ```Visual Studio```, there make sure you have selected ```Release``` in the top and right click ```ALL_BUILD``` and select build
5. After that there will be an executable at the ```Release``` folder in the build directory that you decided

Dependencies for building:
- Ogre3d
- g++
- Nlohmann json
- Cmake
- Visual Studio (Windows users)