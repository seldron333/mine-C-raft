#include <OgreApplicationContext.h>
#include <Ogre.h>
#include <Debug.hpp>
#include <World.hpp>
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

        #pragma region 
        BlockEntity = mng->createEntity(SceneManager::PrefabType::PT_CUBE);
        BlockEntity->setMaterialName("Examples/Rockwall");
        camN->setPosition(Vector3(0,105,0));
        #pragma endregion
    }
    #include <string>
    void SetBlock(int x, int y, int z)//, BlockClass BL)
    {
        SceneNode* node = mng->getRootSceneNode()->createChildSceneNode();
        node->attachObject(BlockEntity->clone(std::to_string(random()*random())));
        node->setScale(Vector3(0.01,0.01,0.01));
        node->setPosition(Vector3(x,y,z));
        Debug::Log("placed");
    }
};
int main()
{
    App mc;
    mc.initApp();
    for (int i = 0; i < 100; i++){
        for (int j = -24; j < 25; j++){
            for (int k = -24; k < 25; k++){mc.SetBlock(j,i,k);}}}
    mc.getRoot()->startRendering();
    mc.closeApp();
    return 0;
}