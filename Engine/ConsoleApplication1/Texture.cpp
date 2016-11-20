#include "Texture.h"

Texture::Texture(string fileName) {
    Image image = RecourceLoader::loadTexture(fileName);

    if (&(image.data) == NULL)
        cerr << "Texture loading Failed!" << endl;

    glBindTexture(1, textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(image.data));
}


Texture::~Texture() {
    glDeleteTextures(1, &textureID);
}

GLuint Texture::getID() {
    return textureID;
}

void Texture::Bind(unsigned int unit) {
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, textureID);
}
