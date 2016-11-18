#include "Shader.h"


void Shader::addProgram(char* data, GLenum type, int length) {
    int shader = glCreateShader(type);

    if(shader == 0)
        cout << "Shader creation Failed! No Memory Location in Shader!" << endl;

    glShaderSource(shader, 1, &data, &length);
    glCompileShader(shader);

    if (!checkShaderErrors(shader))
        return ;

    glAttachShader(program, shader);
    glDeleteShader(shader);
}

bool Shader::checkShaderErrors(int shader) {
    //by Possseidon
    int blen;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &blen);

    if (blen <= 1)
        return true;

    char* infoLog = new char[blen];
    int slen;
    glGetShaderInfoLog(shader, blen, &slen, infoLog);
    cout << "Shader Error in " << endl << infoLog << endl;
    delete[] infoLog;

    return false;
}

bool Shader::checkProgramErrors() {
    int blen;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &blen);
    if (blen <= 1)
        return true;

    char* infoLog = new char[blen];
    int slen;
    glGetProgramInfoLog(program, blen, &slen, infoLog);
    cout << "Linking Error:" << endl << infoLog << endl;
    delete[] infoLog;

    return false;
}

Shader::Shader() {
    program = glCreateProgram();

    if (program == 0) 
        cout << "Shader creation Failed! No Memory Location in Contructor!" << endl;
}


Shader::~Shader() {
}

void Shader::addVertexShader(char* data, int length) {
    addProgram(data, GL_VERTEX_SHADER, length);
}

void Shader::addGeometryShader(char* data, int length) {
    addProgram(data, GL_GEOMETRY_SHADER, length);
}

void Shader::addFragmentShader(char* data, int length) {
    addProgram(data, GL_FRAGMENT_SHADER, length);
}

void Shader::compileShader() {
    glLinkProgram(program);

    if (!checkProgramErrors())
        return;
}

void Shader::bind() {
    glUseProgram(program);
}

