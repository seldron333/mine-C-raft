#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <Debug.hpp>
#include <World.hpp>
#include <GraphicsMain.hpp>
#include <Models.hpp>
using namespace Ogre;
using namespace OgreBites;

std::map<Keycode,bool> KeysPressed;
float CameraSensibility = 0.001;





bool App::mouseMoved(const MouseMotionEvent &evt)
{
    camN->yaw(Radian(-evt.xrel * CameraSensibility), Node::TS_PARENT);
    camN->pitch(Radian(-evt.yrel * CameraSensibility), Node::TS_LOCAL);
    return true;
}





bool App::keyPressed(const KeyboardEvent &evt)
{
    KeysPressed[evt.keysym.sym] = true;

/*
    switch (evt.keysym.sym)
    {
    case 'w':
        camN->translate(0, 0, -1, Node::TS_LOCAL);
        break;
    case 's':
        camN->translate(0, 0, 1, Node::TS_LOCAL);
        break;
    case 'd':
        camN->translate(1, 0, 0, Node::TS_LOCAL);
        break;
    case 'a':
        camN->translate(-1, 0, 0, Node::TS_LOCAL);
        break;
    case '\e':
        setWindowGrab(false);
        break;
    case 'l':
        setWindowGrab(true);
        break;
    }*/
    return true;
}





bool App::frameStarted(const FrameEvent &evt)
{
    Debug::Log(evt.timeSinceLastFrame);
    return true;
}





void App::setup()
{
// Setup
    ApplicationContext::setup();
    root = getRoot();
    mng = root->createSceneManager();
    addInputListener(this);
    RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(mng);

// Camera and lighting
    mng->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    cam = mng->createCamera("FirstPersonCam");
    cam->setNearClipDistance(0.01);
    cam->setAutoAspectRatio(true);
    camN = mng->getRootSceneNode()->createChildSceneNode();
    camN->attachObject(cam);
    getRenderWindow()->addViewport(cam)->setBackgroundColour(ColourValue(float(135) / 255, float(206) / 255, float(235) / 255));
    camN->setPosition(Vector3(0, 105, 0));

// Mesh and rendering
    Models::GenerateMeshes();
    BaseBlockEntity = mng->createEntity("UpMesh");
    setWindowGrab(true);
}





void App::SetBlock(int x, int y, int z)
{
    SceneNode* node = mng->getRootSceneNode()->createChildSceneNode();
    node->attachObject(BaseBlockEntity->clone("Block (" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")"));
    node->setPosition(x, y, z);
}





App mc;
int main()
{
    mc.initApp();
    SceneNode* node = mc.mng->getRootSceneNode()->createChildSceneNode();
    node->attachObject(mc.BaseBlockEntity->clone("gfhfdghgfdgfhdf"));
    node->setPosition(0, 105, -5);
    mc.getRoot()->startRendering();
    mc.closeApp();
    return 0;
}