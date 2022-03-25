#pragma once
#include "GraphicsHeader.hpp"

class IndexBuffer
{
private:
    GLuint rendererid;
    GLuint count;
public:
    IndexBuffer(GLuint* data, GLuint Count);
    ~IndexBuffer();

    void Bind();
    void UnBind();
    inline GLuint GetCount() { return count;}
};