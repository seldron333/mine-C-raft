import os
import shutil

maincwd = os.getcwd()

class program:
    name = ""
    git = ""
    args = ""
    def __init__(self, name, git, args):
        self.name = name
        self.git = git
        self.args = args
    
def install(p):
    os.makedirs("build/ExternalProjects/"+p.name, exist_ok=True)
    if len(os.listdir("build/ExternalProjects/"+p.name)) == 0:
        os.system("git clone "+p.git+" build/ExternalProjects/"+p.name)
    else:
        output = input(p.name+" may already be downloaded, Redownload? (y/n): ")
        if output == "y":
            shutil.rmtree("build/ExternalProjects/"+p.name)
            os.makedirs("build/ExternalProjects/"+p.name)
            os.system("git clone "+p.git+" build/ExternalProjects/"+p.name)
        elif output == "n": pass
        else: 
            print("Invalid input")
            input("Press enter to close")
            quit()
    os.makedirs("build/ExternalProjects/"+p.name+"/build", exist_ok=True)
    os.chdir("build/ExternalProjects/"+p.name+"/build")
    os.system('cmake -GNinja '+p.args+' ..')
    os.system('ninja')
    os.system('ninja install')
    os.chdir(maincwd)
    
install(program("Ogre","https://github.com/OGRECave/ogre.git", '-DCMAKE_INSTALL_PREFIX:PATH="'+maincwd+'/Includes" -DCMAKE_BUILD_TYPE:STRING="Release" -DOGRE_BUILD_SAMPLES:BOOL="0" -DOGRE_ASSERT_MODE:STRING="0" -DOGRE_BUILD_COMPONENT_PYTHON:BOOL="0" -DOGRE_INSTALL_DOCS:BOOL="0" -DOGRE_INSTALL_SAMPLES:BOOL="0" -DOGRE_BUILD_COMPONENT_CSHARP:BOOL="0"'))
install(program("Json","https://github.com/nlohmann/json.git",'-DJSON_BuildTests:BOOL="0" -DJSON_ImplicitConversions:BOOL="0" -DJSON_Install:BOOL="1" -DCMAKE_INSTALL_PREFIX:PATH="'+maincwd+'/Includes" -DBUILD_TESTING:BOOL="0"'))