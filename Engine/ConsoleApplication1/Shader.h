#pragma once

#include "OpenGL.h"
#include "RecourceLoader.h"
#include <iostream>
using namespace std;

enum ShaderType{
    VertexShader,
    GeometryShader,
    FragmentShader,

    NUM_SHADERS
};

class Shader {
private:
    
    GLuint program;
    GLuint shaders[NUM_SHADERS];

    static GLuint creatShader(const string& text, GLenum type);
    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
public:
    Shader(const string& fileName);
    void bind();
    ~Shader();
};