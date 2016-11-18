#pragma once

#include "OpenGL.h"
#include "RecourceLoader.h"
#include "m_vector.h"
#include "m_matrix.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

enum ShaderType{
    VertexShader,
    GeometryShader,
    FragmentShader,

    NUM_SHADERS
};

struct GLSLAttribute {
    GLuint location;
    GLuint size;
    GLenum type;
    int offset;
};

class Shader {
private:
    vector<GLSLAttribute> attributes;
    int stride;

    unordered_map<string, int> uniforms;
    
    GLuint program;
    GLuint shaders[NUM_SHADERS];

    void addUniform(string uniform);

    static GLuint createShader(const string& text, GLenum type);
    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
public:
    Shader(const string& fileName);
    void bind();
    ~Shader();

    void addAttribute(string name, GLenum type, int size);
    GLSLAttribute getGLSLAttribute(int i);
    int getGLSLAttributeCount();
    int getGLSLALSKJFHJKADSHFJKSDHFJKHSTride();

    GLint getUniformLocation(string uniform);

    void setUniformI(GLint uniformLocation, int value);
    void setUniformF(GLint uniformLocation, float value);
    void setUniformVec3(GLint uniformLocation, vec3 value);
    void setUniformMat4(GLint uniformLocation, mat4 value, GLboolean transpose = GL_FALSE);

};