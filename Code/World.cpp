#include <Debug.hpp>
#include <Enums.hpp>
#include <map>

class ChunkClass;
std::map<std::pair<int, int>, ChunkClass> ChunkMap; // Loaded chunks list

namespace BlockClasses
{

    class Block // Block class
    {
    public:
        static BlockIds Id;
    };
    class Dirt : public Block
    {
        Dirt() //: Id()
        {
        }
    };
};

namespace EntityClasses // Entity class
{

    class Entity
    {
        
    };

};

class ChunkClass // Chunk class
{

public:
    const int x, z;
    BlockClasses::Block Blocks[16][255][16];
    ChunkClass(const int x, const int z) : x(x), z(z) // Chunk constructor
    {
    }
};

void Test()
{
    ChunkClass ch(3, 2);
}