#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <iostream>
class App : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    App() : OgreBites::ApplicationContext("minecraft")
    {
    }
    bool keyPressed(const OgreBites::KeyboardEvent& evt)
    {
        if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
        {
            getRoot()->queueEndRendering();
        }
        return true;
    }
    void setup()
    {
        OgreBites::ApplicationContext::setup();
        addInputListener(this);
        Ogre::Root* root = getRoot();
        Ogre::SceneManager* scenemng = root->createSceneManager();
        Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
        shadergen->addSceneManager(scenemng);

        Ogre::Light* light = scenemng->createLight("MainLight");
        Ogre::SceneNode* lightNode = scenemng->getRootSceneNode()->createChildSceneNode();
        lightNode->setPosition(0, 10, 15);
        lightNode->attachObject(light);

        Ogre::SceneNode* camNode = scenemng->getRootSceneNode()->createChildSceneNode();
        camNode->setPosition(0, 0, 15);
        camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

        Ogre::Camera* cam = scenemng->createCamera("myCam");
        cam->setNearClipDistance(5);
        cam->setAutoAspectRatio(true);
        camNode->attachObject(cam);

        getRenderWindow()->addViewport(cam);

        Ogre::Entity* ent = scenemng->createEntity("Sinbad.mesh");
        Ogre::SceneNode* node = scenemng->getRootSceneNode()->createChildSceneNode();
        node->attachObject(ent);
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