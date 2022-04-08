#include <Enums.hpp>
#include <Ogre.h>
class BlockClass
{
public:
    static BlockIds id;
    Ogre::SceneNode *Node;
};
class Chunk
{
public:
    const int x, y;
    BlockClass Blocks[16][256][16];
    Chunk(int x, int y);
};