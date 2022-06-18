#include <Ogre.h>
#include <GraphicsMain.hpp>


namespace Models
{
    void GenerateMeshes()
    {
        mc.mng.
        ManualObject* Up = mc.mng->createManualObject();
        Up->begin();

        Up->position(0,0,0);
        Up->normal(0,1,0);

        Up->position(1,0,0);
        Up->normal(0,1,0);

        Up->position(1,0,1);
        Up->normal(0,1,0);

        Up->position(0,0,1);
        Up->normal(0,1,0);

    }
}