#include "stdafx.h"

#include "RecourceLoader.h"

#include "Texture.h"

Texture::Texture(uint count, uint width, uint height) {
    textureCount = count;

    this->width = width;
    this->height = height;

    textureID = new GLuint[textureCount];
    glGenTextures(textureCount, textureID);

    for (uint i = 0; i < textureCount; i++) {
        addEmptyTexture(i);
    }
}

Texture::Texture(uint count) : Texture("", count){}

Texture::Texture(vector<string> fileNames) {
    loadTextures(fileNames);
}

Texture::Texture(string fileName, uint count) {
    vector<string> fileNames;
    for (int i = 0; i < count; i++)
        fileNames.push_back(fileName);

    loadTextures(fileNames);
}

Texture::~Texture() {
    if(textureID[0])glDeleteTextures(textureCount, textureID);
    delete[] textureID;
}

void Texture::loadTextures(vector<string> fileNames) {
    textureCount = fileNames.size();

    width = 0;
    height = 0;

    textureID = new GLuint[textureCount];
    glGenTextures(textureCount, textureID);

    for (uint i = 0; i < textureCount; i++) {
        loadTexture(i, fileNames[i]);
    }
}

void Texture::addTexture(uint id, unsigned char* data, GLenum wrapS, GLenum wrapT, GLenum minFilter, GLenum magFilter, int baseLevel, int maxLevel) {
    glBindTexture(GL_TEXTURE_2D, textureID[id]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, baseLevel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, maxLevel);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void Texture::addEmptyTexture(uint id) {
    addTexture(id, 0, GL_CLAMP, GL_CLAMP, GL_LINEAR, GL_LINEAR);
}

void Texture::loadTexture(uint id, string fileName) {
    Image image = RecourceLoader::loadTexture(fileName);

    if ((width != 0 && height != 0) && (this->width != image.width || this->height != image.height)) {
        cerr << "Image sizes in 1 Texture do not fit! " << endl;
    }

    this->width = image.width;
    this->height = image.height;

    addTexture(id, image.data.data(), GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST);
}

GLuint Texture::getID(uint id) {
    return textureID[id];
}

void Texture::bind(uint unit, uint id) {
    assert(unit >= 0 && unit < 32);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, textureID[id]);
}