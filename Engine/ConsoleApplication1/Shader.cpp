#include "Shader.h"

GLuint getDataSize(GLenum dataType) {
    switch (dataType) {
    case GL_BYTE:
    case GL_UNSIGNED_BYTE:
        return 1;
    case GL_SHORT:
    case GL_UNSIGNED_SHORT:
        return 2;
    case GL_INT:
    case GL_UNSIGNED_INT:
    case GL_FLOAT:
        return 4;
    case GL_DOUBLE:
        return 8;
    default:
        return 0;
    }
}

GLuint Shader::createShader(const string & text, GLenum type) {
    GLuint shader = glCreateShader(type);

    if (shader == 0)
        cerr << "Error Shader creation failed!" << endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringsLength[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringsLength[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLength);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

    return shader;
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string & errorMessage) {
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if (isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if (success == GL_FALSE) {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        cerr << errorMessage.c_str() << ": '" << error << "'" << endl;
    }
}

Shader::Shader(const string & fileName) {
    program = glCreateProgram();

    shaders[VertexShader] = createShader(RecourceLoader::loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    //shaders[GeometryShader] = createShader(RecourceLoader::loadShader(fileName + ".gs"), GL_GEOMETRY_SHADER);
    shaders[FragmentShader] = createShader(RecourceLoader::loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for (int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(program, shaders[i]);

    glLinkProgram(program);
    checkShaderError(program, GL_LINK_STATUS, true, "Error: Shadersprogram " + fileName + " failed to link: ");

    glValidateProgram(program);
    checkShaderError(program, GL_VALIDATE_STATUS, true, "Error: Shadersprogram " + fileName + " failed to validate: ");
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::addUniform(string uniform) {
    GLint uniformLocation = glGetUniformLocation(program, uniform.c_str());
    
    if (uniformLocation == 0xFFFFFFFF) {
        cerr << "Error: could not find uniform " + uniform + "!";
    }
    
    uniforms[uniform] = uniformLocation;
}

GLint Shader::getUniformLocation(string uniform) {
    if (uniforms.find(uniform) == uniforms.end())
        addUniform(uniform);
    return uniforms[uniform];
}

void Shader::setUniformI(GLint uniformLocation, int value) {
    bind();
    glUniform1i(uniformLocation, value);
}

void Shader::setUniformF(GLint uniformLocation, float value) {
    bind();
    glUniform1f(uniformLocation, value);
}

void Shader::setUniformVec3(GLint uniformLocation, vec3 value) {
    bind();
    glUniform3f(uniformLocation, value.x, value.y, value.z);
}

void Shader::setUniformMat4(GLint uniformLocation, mat4 value, GLboolean transpose) {
    bind();
    glUniformMatrix4fv(uniformLocation, 1, transpose, (float*)&value);
}

Shader::~Shader() {
    for (int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
}

void Shader::addAttribute(string name, GLenum type, int size) {
    GLSLAttribute d;
    d.location = glGetAttribLocation(program, name.c_str());
    d.size = size;
    d.type = type;
    d.offset = stride;
    stride += size * getDataSize(type);

    attributes.push_back(d);

}

GLSLAttribute Shader::getGLSLAttribute(int i) {
    return attributes[i];
}

int Shader::getGLSLAttributeCount() {
    return attributes.size();
}

int Shader::getGLSLALSKJFHJKADSHFJKSDHFJKHSTride() {
    return stride;
}

