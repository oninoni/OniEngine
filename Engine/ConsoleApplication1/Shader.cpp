#include "Shader.h"

GLuint Shader::creatShader(const string & text, GLenum type) {
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

    shaders[VertexShader] = creatShader(RecourceLoader::loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    //shaders[GeometryShader] = creatShader(RecourceLoader::loadShader(fileName + ".gs"), GL_GEOMETRY_SHADER);
    shaders[FragmentShader] = creatShader(RecourceLoader::loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for (int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(program, shaders[i]);

    glBindAttribLocation(program, 0, "position");

    glLinkProgram(program);
    checkShaderError(program, GL_LINK_STATUS, true, "Error: Shadersprogram " + fileName + " failed to link: ");

    glValidateProgram(program);
    checkShaderError(program, GL_VALIDATE_STATUS, true, "Error: Shadersprogram " + fileName + " failed to validate: ");
}

void Shader::bind() {
    glUseProgram(program);
}

Shader::~Shader() {
    for (int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
}
