#include "stdafx.h"

#include "Shader.h"

#include "UniformBufferObject.h"

UniformBufferObject::UniformBufferObject() {
    glGenBuffers(1, &ubo);

    binding = bindingCount;
    bindingCount++;
}

UniformBufferObject::~UniformBufferObject() {
    glDeleteBuffers(1, &ubo);
}

int UniformBufferObject::bindingCount = 0;

void UniformBufferObject::bind() {
    glBindBuffer(GL_UNIFORM_BUFFER, ubo);
}

void UniformBufferObject::generate(int size, GLenum usage) {
    bind();
    glBufferData(GL_UNIFORM_BUFFER, size, NULL, usage);
}

void UniformBufferObject::setData(int offset, int size, void * data) {
    bind();
    glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
}

void UniformBufferObject::bindToShader(Shader * shader, string name) {
    bind();
    GLuint blockIndex = glGetUniformBlockIndex(shader->getProgramID(), name.c_str());
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, ubo);
    glUniformBlockBinding(shader->getProgramID(), blockIndex, binding);
}