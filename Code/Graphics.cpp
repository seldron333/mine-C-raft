#define GL_GLEXT_PROTOTYPES
#include </usr/include/GLFW/glfw3.h>
#include "Base.cpp"
#include <iostream>
using namespace std;

void StartGraphics()
{
    //Initialize glfw
    glfwInit();

    float positions[6] = 
    {
        -0.5, 0.5,
        0.5, 0.5,
        0.5, -0.5
    };

    //Define window
    GLFWwindow* wd= glfwCreateWindow(900, 800, "mineCraft++", NULL, NULL);
    //Make current context
    glfwMakeContextCurrent(wd);
    //Buffers
    GLuint* buffer;
    glGenBuffers(1, buffer);
    glBindBuffer(GL_ARRAY_BUFFER, *buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
    //Vertex
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);
    

    //Startup
    BaseFunctions::Start();
    //Main loop
    while (!glfwWindowShouldClose(wd))
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(wd);
        glfwPollEvents();
    }
    //Terminate
    glfwTerminate();
}