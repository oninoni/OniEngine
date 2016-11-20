#include "Texture.h"

Texture::Texture(string fileName) {
    Image image = RecourceLoader::loadTexture(fileName);

    if (&(image.data) == NULL)
        cerr << "Texture loading Failed!" << endl;

    glGenTextures(1, &textureID);

    bind(0);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width = image.width;
    int height = image.height;
    vector<unsigned char> data = image.data;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());
}


Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

GLuint Texture::getID() {
    return textureID;
}

void Texture::bind(unsigned int unit) {
    assert(unit >= 0 && unit < 32);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, textureID);
}
