#include "../Headers/VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* data)
{
    glGenBuffers(1, &rendererid);
    glBindBuffer(GL_ARRAY_BUFFER, rendererid);
    std::cout<<sizeof(data);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}
VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &rendererid);
}
void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, rendererid);
}
void VertexBuffer::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}