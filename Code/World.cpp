#include <Ogre.h>
#include <Debug.hpp>
#include <Enums.hpp>
#define CreateBlock(Name) class Name : public BlockClass
class BlockClass
{
public:
    static BlockIds id;
    Ogre::SceneNode* Node;
private:
    BlockClass()
    {}
};
class Chunk
{
public:
    BlockClass Blocks[16][256][16];
};
CreateBlock(Stone){};
CreateBlock(Dirt){};
CreateBlock(Grass){};