#pragma once

#include "OpenGL.h"
#include <iostream>
#include "Vertex.h"

class Mesh {
private:

    enum {
        POSITION_VB,

        NUM_BUFFERS
    };

    GLuint vao;
    GLuint vaoBuffers[NUM_BUFFERS];
    unsigned int drawCount;
public:
    Mesh(Vertex* vertices, unsigned int n);
    ~Mesh();

    void render();
};

