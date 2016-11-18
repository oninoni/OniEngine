#pragma once

#include "OpenGL.h"
#include <iostream>
using namespace std;

class Shader {
private:
    bool checkShaderErrors(int shader);
    bool Shader::checkProgramErrors();

    int program;

    void addProgram(char* data, GLenum type, int length);
public:
    Shader();
    ~Shader();

    void addVertexShader(char* data, int length);
    void addGeometryShader(char* data, int length);
    void addFragmentShader(char* data, int length);

    void compileShader();

    void bind();
};