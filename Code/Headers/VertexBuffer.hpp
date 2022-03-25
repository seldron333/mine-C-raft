#pragma once
#include "GraphicsHeader.hpp"

class VertexBuffer
{
private:
    GLuint rendererid;
public:
    VertexBuffer(const void *data);
    ~VertexBuffer();

    void Bind();
    void UnBind();
};