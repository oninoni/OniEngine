#include "RecourceLoader.h"

char * RecourceLoader::loadShader(string fileName, int & length) {

    ifstream shaderFile(fileName);
    if (!shaderFile.good()) {
        cout << "Cant open Shader file " << fileName << "!" << endl;
        return NULL;
    }

    stringstream buffer;
    buffer << shaderFile.rdbuf();

    length = buffer.str().size();
    char* data = new char[length + 1];
    buffer.read(data, length);
    data[length] = 0;

    return data;
}
