#include <Debug.hpp>
#include <Enums.hpp>
#define CreateBlock(Name) class Name : public BlockClass {}
class BlockClass
{
    public:
    static BlockIds id;
};

CreateBlock(Stone);
CreateBlock(Dirt);
CreateBlock(Grass);