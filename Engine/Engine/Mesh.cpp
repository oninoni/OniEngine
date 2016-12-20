#include "stdafx.h"

#include "Vertex.h"

#include "RecourceLoader.h"
#include "Shader.h"
#include "PhongShader.h"

#include "ShaderHandler.h"

#include "Mesh.h"

Mesh::Mesh(ShaderHandler* shaderHandler, Vertex* vertices, uint nVert){
    init(shaderHandler, vertices, nVert);
}

Mesh::Mesh(ShaderHandler* shaderHandler, string fileName) : Mesh(*(RecourceLoader::loadMesh(fileName, shaderHandler))){
}

Mesh::Mesh(ShaderHandler* shaderHandler, MeshType type, float scale) {
    Vertex* vertices;
    uint nVert;
    switch (type) {
    default:
    case Plane:
        nVert = 6;
        vertices = new Vertex[nVert];

        vertices[0] = Vertex(vec3(-1, -1, 0), vec3(0, 0, 1), vec2(0    , scale), vec3(1, 0, 0), vec3(0, 1, 0));
        vertices[1] = Vertex(vec3( 1, -1, 0), vec3(0, 0, 1), vec2(scale, scale), vec3(1, 0, 0), vec3(0, 1, 0));
        vertices[2] = Vertex(vec3(-1,  1, 0), vec3(0, 0, 1), vec2(0    , 0    ), vec3(1, 0, 0), vec3(0, 1, 0));
        vertices[3] = Vertex(vec3( 1, -1, 0), vec3(0, 0, 1), vec2(scale, scale), vec3(1, 0, 0), vec3(0, 1, 0));
        vertices[4] = Vertex(vec3( 1,  1, 0), vec3(0, 0, 1), vec2(scale, 0    ), vec3(1, 0, 0), vec3(0, 1, 0));
        vertices[5] = Vertex(vec3(-1,  1, 0), vec3(0, 0, 1), vec2(0    , 0    ), vec3(1, 0, 0), vec3(0, 1, 0));
        break;
    case Cube:
        nVert = 6 * 6;
        vertices = new Vertex[nVert];

        //NOPE!!!!!!!!!!
        break;
    }
    init(shaderHandler, vertices, nVert);
    delete[] vertices;
}

Mesh::~Mesh() {
    glDeleteBuffers(NUM_BUFFERS, vaoBuffers);
    glDeleteVertexArrays(1, &vao);
}

void Mesh::init(ShaderHandler* shaderHandler, Vertex * vertices, uint nVert) {
    glGenVertexArrays(1, &vao);
    drawCount = nVert;

    glBindVertexArray(vao);

    glGenBuffers(NUM_BUFFERS, vaoBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, vaoBuffers[VERTICE_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * nVert, vertices, GL_STATIC_DRAW);

    Shader* shader = shaderHandler->getPhongShader();

    for (int j = 0; j < shader->getGLSLAttributeCount(); j++) {
        GLSLAttribute attribute = shader->getGLSLAttribute(j);

        glEnableVertexAttribArray(attribute.location);
        glVertexAttribPointer(
            attribute.location,
            attribute.size,
            attribute.type,
            GL_FALSE,
            shader->getStride(),
            (void*)attribute.offset
        );
    }
    


}

void Mesh::render() {
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);
}