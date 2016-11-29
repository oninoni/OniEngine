#include "stdafx.h"

#include "TextureArrayFramebuffer.h"

TextureArrayFramebuffer::TextureArrayFramebuffer(uint width, uint height, GLenum format, vector<GLenum> attachments) : TextureArray(attachments.size(), width, height, format){
    framebuffer = new GLuint[this->layers];
    glGenFramebuffers(this->layers, framebuffer);

    for (uint i = 0; i < this->layers; i++) {
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[i]);
        glFramebufferTextureLayer(GL_FRAMEBUFFER, attachments[i], textureID, 0, i);
    }

    int err = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (err != GL_FRAMEBUFFER_COMPLETE) {
        cerr << "Framebuffer creation is not complete! Kot: " << err << endl;
        assert(false);
    }
}

TextureArrayFramebuffer::TextureArrayFramebuffer(uint layers, uint width, uint height, GLenum format, GLenum attachment) : 
TextureArrayFramebuffer(width, height, format, vector<GLenum>(layers, attachment)){}

TextureArrayFramebuffer::~TextureArrayFramebuffer() {
    if (framebuffer) glDeleteFramebuffers(layers, framebuffer);
    delete[] framebuffer;
}

void TextureArrayFramebuffer::bindFramebuffer(uint layer) {
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer[layer]);
    glViewport(0, 0, width, height);
}