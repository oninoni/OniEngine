#pragma once
class TextureArray {
protected:
    uint width, height, layers;

    GLuint textureID;
public:
    TextureArray(uint layers, uint width, uint height, GLenum format = GL_RGBA);
    ~TextureArray();

    void bind(uint unit);

    void loadImage(uint layer, string fileName);
};