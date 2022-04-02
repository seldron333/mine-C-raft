#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <GraphicsWorldGeneration.hpp>
using namespace Ogre;
using namespace OgreBites;

class App : public ApplicationContext, public InputListener
{
public:
    SceneNode* cm;
    App() : ApplicationContext("minecraft")
    {
    }
    void setup()
    {
        ApplicationContext::setup();
        getRoot()->restoreConfig();
        addInputListener(this);
        Root* root = getRoot();
        SceneManager* scenemng = root->createSceneManager();
        RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
        shadergen->addSceneManager(scenemng);

        scenemng->setAmbientLight(ColourValue(0.5,0.5,0.5));
        SceneNode* camNode = scenemng->getRootSceneNode()->createChildSceneNode();
        cm = camNode;

        Camera* cam = scenemng->createCamera("myCam");
        cam->setNearClipDistance(0.01);
        cam->setAutoAspectRatio(true);
        camNode->attachObject(cam);

        getRenderWindow()->addViewport(cam)->setBackgroundColour(ColourValue(float(135)/255, float(206)/255, float(235)/255));;

        
        Entity* ent = scenemng->createEntity(SceneManager::PrefabType::PT_CUBE);
        ent->setMaterialName("Examples/BumpyMetal");
        SceneNode* node = scenemng->getRootSceneNode()->createChildSceneNode();
        node->attachObject(ent);
        node->setScale(Vector3(0.01,0.01,0.01));
        node->setPosition(Vector3(0,0,0.5));
        root->showConfigDialog(NULL);
    }
};
int main()
{
    App mc;
    mc.initApp();
    mc.getRoot()->startRendering();
    mc.closeApp();
    return 0;
}