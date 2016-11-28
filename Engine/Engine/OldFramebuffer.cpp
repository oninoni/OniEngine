#include "stdafx.h"

#include "OldFramebuffer.h"

TextureRenderTarget::TextureRenderTarget(vector<GLenum> attachments, uint width, uint height, GLenum format) : Texture(attachments.size() * 2, width, height, format){
    frameBuffer = 0;

    if ((attachments.size() * 2) != textureCount) {
        cerr << "Texture Count does not fit attachment Count in a TextureRenderTarget!" << endl;
    }

    initRenderTarget(attachments);
}

TextureRenderTarget::~TextureRenderTarget() {
    if (frameBuffer) glDeleteFramebuffers(1, &frameBuffer);
}


void TextureRenderTarget::initRenderTarget(vector<GLenum> attachments) {
    if (attachments.size() == 0)
        return;

    GLenum* drawBuffers = new GLenum[textureCount];

    if (frameBuffer == NULL) {
        glGenFramebuffers(1, &frameBuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    }

    for (uint i = 0; i < textureCount; i = i + 2) {
        if (attachments[i] == GL_DEPTH_ATTACHMENT || attachments[i] == GL_STENCIL_ATTACHMENT) {
            drawBuffers[i] = GL_NONE;
        }
        else {
            drawBuffers[i] = attachments[i];
        }

        if (attachments[i] == GL_NONE)
            continue;

        glFramebufferTexture(GL_FRAMEBUFFER, attachments[i], textureID[i], 0);
    }

    if (frameBuffer == 0) {
        cerr << "Framebuffer not generated!" << endl;
        assert(false);
    }

    glDrawBuffers(textureCount, drawBuffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        cerr << "Framebuffer not completed!" << endl;
        assert(false);
    }

    delete[] drawBuffers;
}

void TextureRenderTarget::bindAsRenderTarget() {
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glViewport(0, 0, width, height);
    for (uint i = 0; i < textureCount; i = i + 2) {
        glBindTexture(GL_TEXTURE_2D, textureID[i + 1]);
        glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, width, height, GL_FALSE);
    }
}

void TextureRenderTarget::bind(uint unit, uint id) {
    Texture::bind(unit, id + 1);
}