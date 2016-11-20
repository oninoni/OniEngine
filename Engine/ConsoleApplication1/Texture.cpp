#include "Texture.h"

Texture::Texture(string fileName) {
    Image image = RecourceLoader::loadTexture(fileName);

    glGenTextures(1, &textureID);

    bind(0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data.data());

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
