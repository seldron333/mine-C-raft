class Blocks
{
public:
    enum BlockTypes : short
    {
        air,
        grass,
        dirt,
        stone
    };
    class BlockParent
    {
    public:
        BlockTypes block_id = air;
        void WhenUpdated()
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
};