#include <vector>
#include <GraphicsHeader.hpp>
struct VertexBufferElement
{
    GLuint Ecount;
    GLuint Etype;
    bool Enormalises;
};
class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> Elements;

public:
    VertexBufferLayout()
    {
    }
    void Push(int count)
    {
        
    }
    void Push(int count)
    {
        Elements.push_back((VertexBufferElement){GL_FLOAT, count, false});
    } 
};