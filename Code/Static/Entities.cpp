namespace Entities
{
    enum EntityTypes
    {
        cow,
        chicken,
        pig
    };
    class EntityParent
    {
    public:
        long x, y, z;
        EntityTypes entity_id;
    };
    class Cow : public EntityParent
    {
        Cow()
        {
            this->entity_id = cow;
        }
    };
    class Chicken : public EntityParent
    {
        Chicken()
        {
            this->entity_id = chicken;
        }
    };
    class Pig : public EntityParent
    {
        Pig()
        {
            this->entity_id = pig;
        }
    };
};