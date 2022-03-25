#include <BaseHeader.hpp>
namespace WorldGeneration
{
    void SetForEachBlock(int xmin, int ymin, int zmin, int xmax, int ymax, int zmax, Chunk& chnk, Blocks::BlockTypes type)
    {
        for (int x = xmin; x <= xmax; x++)
        {
            for (int y = ymin; y < ymax; y++)
            {
                for (int z = zmin; z < zmax; z++)
                {
                    SetBlock(chnk.blocks[x][y][z], type);
                }
            }
        }
    }
    void GenerateChunk(Chunk& ch)
    {
        SetForEachBlock(0, 0, 0, 16, 100, 16, ch, Blocks::stone);
    }
};