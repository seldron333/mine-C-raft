#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <GraphicsWorldGeneration.hpp>
using namespace Ogre;
using namespace OgreBites;

class App : public ApplicationContext, public InputListener
{
public:
    Root* root;
    SceneManager* mng;
    Camera* cam;
    SceneNode* camN;
    App() : ApplicationContext("minecraft")
    {
    }
    void setup()
    {
        // Immutable : setup
        #pragma region
        ApplicationContext::setup();
        root = getRoot();
        mng = root->createSceneManager();
        addInputListener(this);
        RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(mng);
        #pragma endregion

        // Immutable : Camera and lighting
        #pragma region 
        mng->setAmbientLight(ColourValue(0.5,0.5,0.5));
        cam = mng->createCamera("FirstPersonCam");
        cam->setNearClipDistance(0.01);
        cam->setAutoAspectRatio(true);
        camN = mng->getRootSceneNode()->createChildSceneNode();
        camN->attachObject(cam);
        getRenderWindow()->addViewport(cam)->setBackgroundColour(ColourValue(float(135)/255, float(206)/255, float(235)/255));;
        #pragma endregion

        SetupGraphicsWorldGeneration(this);
    }
};
int maidens()
{
    App mc;
    mc.initApp();
    mc.getRoot()->startRendering();
    mc.closeApp();
    return 0;
}