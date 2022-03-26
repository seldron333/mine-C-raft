#include <IdEnums.cpp>
namespace Blocks { class BlockParent{}; }
class Chunk { public: Blocks::BlockParent blocks[16][256][16]; };
Blocks::BlockParent &Block(double x, short y, double z);
void UnloadChunk(int x, int z);
void UpdateBlock(int x, int y, int z);
void SetBlock(double x, short y, double z, Blocks::BlockTypes type);
void SetBlock(Blocks::BlockParent &bl, Blocks::BlockTypes type);
void UpdateAdjacentBlocks(int x, int y, int z);
void Start();