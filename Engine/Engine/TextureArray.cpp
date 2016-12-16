#include "stdafx.h"

#include "RecourceLoader.h"

#include "TextureArray.h"

TextureArray::TextureArray(uint layers, uint width, uint height, GLenum format) {
    this->width = width;
    this->height = height;
    this->layers = layers;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D_ARRAY, textureID);
    
    if(format == GL_DEPTH_COMPONENT)
       glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, format, width, height, layers, 0, format, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

TextureArray::~TextureArray() {
    glDeleteTextures(1, &textureID);
}

void TextureArray::loadImage(uint layer, string fileName) {
    Image image = RecourceLoader::loadTexture(fileName);

    if (width == 0 || height == 0 || this->width != image.width || this->height != image.height) {
        cerr << "Image sizes in 1 Texture do not fit! " << endl;
        assert(false);
    }

    glBindTexture(GL_TEXTURE_2D_ARRAY, textureID);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, layer, width, height, 1, GL_RGBA, GL_UNSIGNED_BYTE, image.data.data());
}

void TextureArray::bind(uint unit) {
    assert(unit >= 0 && unit < 32);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D_ARRAY, textureID);
}