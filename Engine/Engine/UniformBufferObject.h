#pragma once

class Shader;

class UniformBufferObject {
private:
    static int bindingCount;

    GLuint ubo;
    int binding;
public:
    UniformBufferObject();
    ~UniformBufferObject();

    void bindToShader(Shader* shader, string name);
    void bind();

    void generate(int size, GLenum usage);
    void setData(int offset, int size, void* data);
};