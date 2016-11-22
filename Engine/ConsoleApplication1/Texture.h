#pragma once

#include "stdafx.h"

class Texture {
private:
    GLuint textureID;
public:
    Texture(string fileName);
    ~Texture();

    GLuint getID();

    void bind(unsigned int unit);
};