#include <GraphicsHeader.hpp>

class IndexBuffer
{
private:
    GLuint rendererid;
    GLuint count;

public:
    IndexBuffer(GLuint *data, GLuint Count)
    {
        glGenBuffers(1, &rendererid);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * Count, data, GL_STATIC_DRAW);
    }
    ~IndexBuffer()
    {
        glDeleteBuffers(1, &rendererid);
    }
    void Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererid);
    }
    void UnBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    inline GLuint GetCount() { return count; }
};
