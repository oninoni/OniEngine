#include "Mesh.h"
Mesh::Mesh(Vertex* vertices, unsigned int n){
    drawCount = n;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(NUM_BUFFERS, vaoBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, vaoBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, drawCount * Vertex::SIZE, vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
}

void Mesh::render() {
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);

    glBindVertexArray(0);
}
