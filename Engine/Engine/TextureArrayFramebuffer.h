#pragma once

#include "TextureArray.h"

class TextureArrayFramebuffer : public TextureArray {
private:
    GLuint* framebuffer;
public:
    TextureArrayFramebuffer(uint width, uint height, GLenum format, vector<GLenum> attachments);
    TextureArrayFramebuffer(uint layers, uint width, uint height, GLenum format, GLenum attachment);
    ~TextureArrayFramebuffer();

    void bindFramebuffer(uint layer);
};