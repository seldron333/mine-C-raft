import os
import shutil
import zipfile

maincwd = os.getcwd()
if maincwd[-1] == '/': maincwd = maincwd[:-1]

class program:
    name = ""
    args = ""
    def __init__(self, name, args):
        self.name = name
        self.args = args
    
def install(p):
    os.makedirs("./build/ExternalProjects")
    os.chdir("./build/ExternalProjects")
    os.makedirs("./"+p.name+"/build")
    zipfile.ZipFile(maincwd+'/Resources/Dependencies/'+p.name+".zip").extractall("./"+p.name)
    os.chdir("./"+p.name+"/build")
    os.system('cmake -GNinja '+p.args+' ..')
    os.system('ninja')
    os.system('ninja install')
    os.chdir(maincwd)

shutil.rmtree('./build',ignore_errors=True)
shutil.rmtree('./Includes',ignore_errors=True)
os.makedirs("./Includes/include/nlohmann",exist_ok=True)
shutil.copyfile("./Resources/Dependencies/json.hpp","./Includes/include/nlohmann/json.hpp")
install(program("Ogre", '-DOGRE_INSTALL_DOCS:BOOL="0" -DOGRE_ASSERT_MODE:STRING="0" -DCMAKE_INSTALL_PREFIX:PATH="'+maincwd+'/Includes" -DOGRE_INSTALL_SAMPLES:BOOL="0" -DCMAKE_BUILD_TYPE:STRING="Release" -DOGRE_BUILD_SAMPLES:BOOL="0"'))