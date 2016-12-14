#pragma once

class ShaderHandler;
class Shader;
class Vertex;

enum MeshType {
    Plane,
    Cube
};

class Mesh {
private:
    enum {
        VERTICE_BUFFER,

        NUM_BUFFERS
    };

    GLuint vao;
    GLuint vaoBuffers[NUM_BUFFERS];
    unsigned int drawCount;
public:
    Mesh(ShaderHandler* shaderHandler, Vertex* vertices, uint nVert);
    Mesh(ShaderHandler* shaderHandler, string fileName);
    Mesh(ShaderHandler* shaderHandler, MeshType type, float scale = 1.0f);
    ~Mesh();

    void init(ShaderHandler* shaderHandler, Vertex* vertices, uint nVert);

    void render();
};

