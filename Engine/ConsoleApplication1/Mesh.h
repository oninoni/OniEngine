#pragma once

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
    ~Mesh();

    void render();
};

