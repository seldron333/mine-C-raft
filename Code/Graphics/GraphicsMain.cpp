#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <iostream>
using namespace Ogre;
using namespace OgreBites;

class App : public ApplicationContext, public InputListener
{
public:
    SceneNode* cm;
    App() : ApplicationContext("minecraft")
    {
    }
    bool keyPressed(const KeyboardEvent& evt)
    {        
        cm->setFixedYawAxis(true);
        if (evt.keysym.sym == SDLK_DOWN)
        {
            cm->translate(Vector3(0,0,1));
        }
        if (evt.keysym.sym == SDLK_UP)
        {
            cm->translate(Vector3(0,0,-1));
        }
        if (evt.keysym.sym == SDLK_LEFT)
        {
            cm->translate(Vector3(-1,0,0));
        }
        if (evt.keysym.sym == SDLK_RIGHT)
        {
            cm->translate(Vector3(1,0,0));
        }
        if (evt.keysym.sym == SDLK_LSHIFT)
        {
            cm->translate(Vector3(0,-1,0));
        }
        if (evt.keysym.sym == SDLK_SPACE)
        {
            cm->translate(Vector3(0,1,0));
        }
        return true;
    }
    void setup()
    {
        ApplicationContext::setup();
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