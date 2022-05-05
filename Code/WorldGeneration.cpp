#include <World.hpp>
#include <Debug.hpp>
#include <GraphicsMain.hpp>
void GenerateChunk(Chunk &ch)
{
    for (int i = -16; i < 16; i++)
    {
        for (int k = -16; k < 16; k++)
        {
            mc.SetBlock(i, 40, k);
        }
    }
}