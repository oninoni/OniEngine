#pragma once

#include "Texture.h"

class TextureRenderTarget : public Texture {
private:
    GLuint frameBuffer;

    void initRenderTarget(vector<GLenum> attachments);
public:
    TextureRenderTarget(vector<GLenum> attachments, uint width, uint height);
    ~TextureRenderTarget();

    void bindAsRenderTarget();
    void bind(uint unit, uint id = 0);
};