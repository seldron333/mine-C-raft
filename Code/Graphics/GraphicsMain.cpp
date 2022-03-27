#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <iostream>
class App : public OgreBites::ApplicationContext
{
public:
    App() : OgreBites::ApplicationContext("minecraft")
    {
        
    }
};
void StartGraphics()
{
    App mc;
    mc.initApp();
    mc.getRoot()->startRendering();
}