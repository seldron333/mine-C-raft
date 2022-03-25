#include "../Headers/IndexBuffer.hpp"

IndexBuffer::IndexBuffer(GLuint* data, GLuint Count) : count(Count)
{
    glGenBuffers(1, &rendererid);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererid);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * Count, data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &rendererid);
}
void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererid);
}
void IndexBuffer::UnBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}