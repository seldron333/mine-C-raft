class WorldGeneration
{
public:
    static void GenerateChunk(auto &Chunk)
    {
        for (int x = 0; x < 16; x++)
        {
            for (int y = 0; y < 100; y++)
            {
                for (int z = 0; z < 16; z++)
                {
                    Chunk.blocks[x][y][z].block_id = 1;
                }
            }
        }
    }
};