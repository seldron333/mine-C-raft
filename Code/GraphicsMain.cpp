#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <Debug.hpp>
using namespace Ogre;
using namespace OgreBites;

class App : public ApplicationContext, public InputListener
{
public:
    Root* root;
    SceneManager* mng;
    Camera* cam;
    SceneNode* camN;
    Entity* BlockEntity;
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
        Entity* lol;
        lol = mng->createEntity(SceneManager::PrefabType::PT_CUBE);


        #pragma region 
        BlockEntity = mng->createEntity(SceneManager::PrefabType::PT_CUBE);
        camN->setPosition(Vector3(0,105,0));
        // for (int i = 0; i < 100; i++)
        // {
        //     for (int j = -24; j < 25; j++)
        //     {
        //         for (int k = -24; k < 25; k++)
        //         {
        //             SceneNode* node = mng->getRootSceneNode()->createChildSceneNode();
        //             node->attachObject(BlockEntity);
        //             node->setScale(Vector3(0.01,0.01,0.01));
        //             node->setPosition(Vector3(j,i,k));
        //         }
                
        //     }
            
        // }
        #pragma endregion
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