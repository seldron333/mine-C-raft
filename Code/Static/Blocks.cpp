#include <IdEnums.cpp>
namespace Blocks
{
    class BlockParent
    {
    public:
        BlockTypes block_id = air;
        void WhenUpdated(int x, int y, int z)
        {
        }
        void WhenTick()
        {
        }
    };
    class Air : public BlockParent
    {
    };
    class Grass : public BlockParent
    {
        Grass()
        {
            this->block_id = grass;
        }
    };
    class Dirt : public BlockParent
    {
        Dirt()
        {
            this->block_id = dirt;
        }
    };
    class Stone : public BlockParent
    {
        Stone()
        {
            this->block_id = stone;
        }
    };
    class Water : public BlockParent
    {
        int State = 7;
        Water(int q)
        {
            this->block_id = water;
            State = q;
        }
        void WhenUpdated(int x, int y, int z)
        {
            if (State == 7)
            {
            }
            else
            {
            }
        }
    };
};