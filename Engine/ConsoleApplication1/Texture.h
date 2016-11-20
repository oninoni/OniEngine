#pragma once

#include "OpenGL.h"
#include "RecourceLoader.h"
#include <string>
#include <assert.h>

using namespace std;

class Texture {
private:
    GLuint textureID;
public:
    Texture(string fileName);
    ~Texture();

    GLuint getID();

    void Bind(unsigned int unit);
};