green='\033[1;33m'
normal='\033[0m'
printf "${green}Updating repositories${normal}\n"
sudo apt update -qq
printf "${green}Installing g++${normal}\n"
sudo apt install -qq g++
printf "${green}Installing cmake${normal}\n"
sudo apt install -qq cmake
printf "${green}Installing git${normal}\n"
sudo apt install -qq git
printf "${green}Installing nlohmann json from github${normal}\n"
sudo git clone https://github.com/nlohmann/json.git
sudo rm -rf /usr/include/nlohmann
sudo mv ./json/include/nlohmann /usr/include
sudo rm -rf ./json
printf "${green}Cloning Ogre3d${normal}\n"
git clone https://github.com/OGRECave/ogre.git
cd ogre
mkdir build
cd build
printf "${green}Making cmake Ogre3d${normal}\n"
cmake ..
printf "${green}Building Ogre3d${normal}\n"
make -j 50
printf "${green}Installing Ogre3d${normal}\n"
sudo make install
sudo rm -rf ../../ogre
