#include "stdafx.h"

#include "Vertex.h"

#include "RecourceLoader.h"
#include "Shader.h"

#include "Mesh.h"

Mesh::Mesh(Shader* shader, Vertex* vertices, uint nVert){
    drawCount = nVert;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(NUM_BUFFERS, vaoBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, vaoBuffers[VERTICE_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * nVert, vertices, GL_STATIC_DRAW);

    for (int i = 0; i < shader->getGLSLAttributeCount(); i++) {
        GLSLAttribute attribute = shader->getGLSLAttribute(i);
        
        glEnableVertexAttribArray(attribute.location);
        glVertexAttribPointer(
            attribute.location,
            attribute.size,
            attribute.type,
            GL_FALSE,
            shader->getGLSLALSKJFHJKADSHFJKSDHFJKHSTride(),
            (void*)attribute.offset
        );
    }
}

Mesh::Mesh(Shader * shader, string fileName) : Mesh(*(RecourceLoader::loadMesh(fileName, shader))){
}

Mesh::~Mesh() {
    glDeleteBuffers(NUM_BUFFERS, vaoBuffers);
    glDeleteVertexArrays(1, &vao);
}

void Mesh::render() {
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);
}