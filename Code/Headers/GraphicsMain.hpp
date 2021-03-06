#include <OgreApplicationContext.h>
#include <Ogre.h>
using namespace Ogre;
using namespace OgreBites;
class BlockClass;
class App : public ApplicationContext, public InputListener
{
public:
    Root* root;
    SceneManager* mng;
    Camera* cam;
    SceneNode* camN;
    MeshPtr BlockMesh;
    Entity* BaseBlockEntity;

    void setup();
    App() : ApplicationContext("minecraft")
    {
    }
    void SetBlock(int x, int y, int z);
    bool keyPressed(const KeyboardEvent& evt);
    bool mouseMoved(const MouseMotionEvent& evt);
    bool frameStarted(const FrameEvent& evt);
};
extern App mc;