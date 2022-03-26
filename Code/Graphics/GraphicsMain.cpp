#include <GeneralHeader.hpp>
#include <GraphicsHeader.hpp>
#include <VertexBuffer.hpp>
#include <IndexBuffer.hpp>
#include <VertexArray.hpp>
#include <fstream>
#include <sstream>

using namespace std;

struct ShaderProgramSource
{
    string VertexSource;
    string FragmentSource;
};

ShaderProgramSource ParseShader()
{
    ifstream file("./Code/Shaders/Basic.shader");
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
        log("error compiling shader");
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
    VertexBuffer vb(positions, 4*2*sizeof(float));

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    IndexBuffer ib(Indices,6);

    ShaderProgramSource source = ParseShader();
    GLuint shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    glUniform4f(location, 0.2f,0.3f,0.8f,1.0f);
    // BaseFunctions::Start();
    while (!glfwWindowShouldClose(wd))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, nullptr);
        glfwSwapBuffers(wd);
        glfwPollEvents();
    }
    glfwTerminate();
}