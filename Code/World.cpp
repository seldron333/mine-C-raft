#include <Ogre.h>
#include <Debug.hpp>
#include <Enums.hpp>
#include <WorldGeneration.hpp>
#include <World.hpp>
#define CreateBlockClass(Name) class Name : public BlockClass
Chunk::Chunk(int x, int y) : x(x), y(y)
{
    GenerateChunk(*this);
}
CreateBlockClass(Stone){};
CreateBlockClass(Dirt){};
CreateBlockClass(Grass){};