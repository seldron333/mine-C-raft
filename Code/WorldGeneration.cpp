#include <World.hpp>
#include <Debug.hpp>
#include <GraphicsMain.hpp>
void GenerateChunk(Chunk &ch)
{
    for (int i = -16; i < 16; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = -16; k < 16; k++)
            {
                mc.SetBlock(i, j, k, ch.Blocks[i][j][k]);
            }
        }
    }
}