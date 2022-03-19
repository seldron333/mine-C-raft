#define GL_GLEXT_PROTOTYPES
#include </usr/include/GLFW/glfw3.h>
#include "Base.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct ShaderProgramSource
{
    string VertexSource;
    string FragmentSource;
};

ShaderProgramSource ParseShader()
{
    ifstream file("/home/seldron/Projects/mine-C-raft/Code/Shaders/Basic.shader");
    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };
    string line;
    stringstream strstr[2];
    ShaderType type = ShaderType::NONE;
    while (getline(file, line))
    {
        if (line.find("#shader") != string::npos)
        {
            if (line.find("vertex") != string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            strstr[(int)type] << line << '\n';
        }
    }
    return {strstr[0].str(), strstr[1].str()};
}

GLuint Compileshader(GLuint type, const string &source)
{
    GLuint id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    GLint res;
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(id, length, &length, message);
        cout << "failed to compile shader: " << message << endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}
GLuint CreateShader(const string &vertexshader, const string &fragmentshader)
{
    GLuint program = glCreateProgram();
    GLuint vertshader = Compileshader(GL_VERTEX_SHADER, vertexshader);
    GLuint fragshader = Compileshader(GL_FRAGMENT_SHADER, fragmentshader);
    glAttachShader(program, vertshader);
    glAttachShader(program, fragshader);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vertshader);
    glDeleteShader(fragshader);

    return program;
}

void StartGraphics()
{
    glfwInit();

    float positions[] =
        {
            -0.5, -0.5,
            0.5, -0.5,
            0.5, 0.5,
            -0.5, 0.5,
        };

    GLuint Indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

    GLFWwindow *wd = glfwCreateWindow(800, 800, "mineCraft++", NULL, NULL);
    glfwMakeContextCurrent(wd);
    glfwSwapInterval(1);
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    GLuint indbuffobj;
    glGenBuffers(1, &indbuffobj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indbuffobj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
    ShaderProgramSource source = ParseShader();
    GLuint shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    glUniform4f(location, 0.2f,0.3f,0.8f,1.0f);
    BaseFunctions::Start();
    while (!glfwWindowShouldClose(wd))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, nullptr);
        glfwSwapBuffers(wd);
        glfwPollEvents();
    }
    glfwTerminate();
}