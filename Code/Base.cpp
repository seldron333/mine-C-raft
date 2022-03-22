#include "./Headers/MainHeader.hpp"
using namespace std;

nlohmann::json Settings;
class Chunk;
map<pair<int, int>, Chunk> Chunks;

template <typename T>
void log(T tx) { cout << tx << endl; }

class Chunk
{
public:
    Blocks::BlockParent blocks[16][256][16]{Blocks::Air()};
    int x;
    int z;
    Chunk(int X, int Z)
    {
        x = X;
        z = Z;
        log("Loaded Chunk: " + to_string(x) + " , " + to_string(z));
        Chunks[{x, z}] = *this;

    }
    Chunk()
    {
    }
};

Blocks::BlockParent &Block(double x, short y, double z)
{
    int xc = int(x / 16);
    int zc = int(z / 16);
    if (Chunks.find({xc, zc}) == Chunks.end())
        Chunk(xc, zc);
    return Chunks[{xc, zc}].blocks[int(x) % 16][y][int(z) % 16];
};
void UnloadChunk(int x, int z)
{
    Chunks.erase({x, z});
    log("Unloaded Chunk: " + to_string(x) + " , " + to_string(z));
}
void InitializeJson()
{
    fstream temp("./Settings.json");
    temp >> Settings;
}
void UpdateBlock(int x, int y, int z)
{
    Block(x, y, z).WhenUpdated(x, y, z);
}
void SetBlock(Blocks::BlockParent& bl, Blocks::BlockTypes type)
{
    bl.block_id = type;
}
void UpdateAdjacentBlocks(int x, int y, int z)
{
    UpdateBlock(x, y, z);
    UpdateBlock(x - 1, y, z);
    UpdateBlock(x + 1, y, z);
    UpdateBlock(x, y - 1, z);
    UpdateBlock(x, y + 1, z);
    UpdateBlock(x, y, z - 1);
    UpdateBlock(x, y, z + 1);
}
class BaseFunctions
{
private:
    BaseFunctions()
    {
    }
public:
    static void Start()
    {
        InitializeJson();
        Chunk(1,1);
    }
};
