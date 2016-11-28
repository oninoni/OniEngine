#pragma once

class Texture {
protected:
    GLuint* textureID;
    int width;
    int height;

    int textureCount;

    void loadTextures(vector<string> fileNames);

    void addTexture(uint id, unsigned char* data, GLenum WRAP_S, GLenum WRAP_T, GLenum MIN_FILTER, GLenum MAG_FILTER, GLenum format, int BASE_LEVEL = 0, int MAX_LEVEL = 0);
    void addEmptyTexture(uint id, GLenum format);
    void loadTexture(uint id, string fileName);
public:
    Texture(uint count, uint width, uint height, GLenum format);
    Texture(uint count = 1);
    Texture(vector<string> fileNames);
    Texture(string fileName, uint count = 1);
    ~Texture();

    GLuint getID(uint id = 0);

    virtual void bind(uint unit, uint id = 0);
};