class WorldGeneration
{
public:
    void SetForEachBlock(int xmin, int ymin, int zmin, int xmax, int ymax, int zmax, Chunk chnk, BlockTypes type)
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
    void GenerateChunk(Chunk ch)
    {
        SetForEachBlock(0, 0, 0, 16, 100, 16, ch,BlockTypes::stone);
    }
};