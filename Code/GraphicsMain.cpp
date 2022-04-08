#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <Debug.hpp>
#include <World.hpp>
#include <GraphicsMain.hpp>
using namespace Ogre;
using namespace OgreBites;

void App::setup()
{
// Immutable : Setup
#pragma region
    ApplicationContext::setup();
    root = getRoot();
    mng = root->createSceneManager();
    addInputListener(this);
    RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(mng);
#pragma endregion

// Immutable : Camera and lighting
#pragma region
    mng->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    cam = mng->createCamera("FirstPersonCam");
    cam->setNearClipDistance(0.01);
    cam->setAutoAspectRatio(true);
    camN = mng->getRootSceneNode()->createChildSceneNode();
    camN->attachObject(cam);
    getRenderWindow()->addViewport(cam)->setBackgroundColour(ColourValue(float(135) / 255, float(206) / 255, float(235) / 255));
    camN->setPosition(Vector3(0, 105, 0));
#pragma endregion

// Immutable : Mesh and rendering
#pragma region
    BaseBlockEntity = mng->createEntity(SceneManager::PrefabType::PT_CUBE);
#pragma endregion
}

void App::SetBlock(int x, int y, int z, BlockClass BL)
{
    SceneNode *node = mng->getRootSceneNode()->createChildSceneNode();
    // if(mng->getEntity)
    node->attachObject(App::BaseBlockEntity->clone("Block ("+std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+")"));
    node->setPosition(Vector3(x, y, z));
}
App mc;
int main()
{
    BlockClass lol;
    mc.initApp();
    Chunk(3,2);
    mc.getRoot()->startRendering();
    mc.closeApp();
    return 0;
}