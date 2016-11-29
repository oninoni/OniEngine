#pragma once

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
    Mesh(Shader* shader, Vertex* vertices, uint nVert);
    Mesh(Shader* shader, string fileName);
    Mesh(Shader* shader, MeshType type, float scale = 1.0f);
    ~Mesh();

    void init(Shader* shader, Vertex* vertices, uint nVert);

    void render();
};

