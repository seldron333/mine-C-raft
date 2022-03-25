#include <GraphicsHeader.hpp>

class VertexBuffer
{
private:
    GLuint rendererid;

public:
    VertexBuffer(const void *data, GLuint size)
    {
        glGenBuffers(1, &rendererid);
        glBindBuffer(GL_ARRAY_BUFFER, rendererid);
        glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), data, GL_STATIC_DRAW);
    }
    ~VertexBuffer()
    {
        glDeleteBuffers(1, &rendererid);
    }
    void Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererid);
    }
    void UnBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};
