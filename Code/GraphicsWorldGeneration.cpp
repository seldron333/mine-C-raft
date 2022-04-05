#include <Ogre.h>
#include <Debug.hpp>
#include <GraphicsMain.hpp>
using namespace Ogre;
class App;
Entity* BlockEntity;
void SetupGraphicsWorldGeneration(App* mc)
{
    BlockEntity = mc->mng->createEntity(SceneManager::PrefabType::PT_CUBE);
    Debug::Log("njuindsndvbjsvdniiidvdhsbhidbi");
    mc->camN->setPosition(Vector3(0,105,0));

/*
    ent->setMaterialName("Examples/BumpyMetal");

    SceneNode* node = mng->getRootSceneNode()->createChildSceneNode();

    node->attachObject(ent);
    node->setScale(Vector3(0.01,0.01,0.01));
    node->setPosition(Vector3(0,0,0.5));*/
    for (int i = 0; i < 100; i++)
    {
        for (int j = -24; j < 25; j++)
        {
            for (int k = -24; k < 25; k++)
            {
                SceneNode* node = mc->mng->getRootSceneNode()->createChildSceneNode();
                node->attachObject(BlockEntity);
                node->setScale(Vector3(0.01,0.01,0.01));
                node->setPosition(Vector3(j,i,k));
            }
            
        }
        
    }
    
}
void CreateBlock()
{

}