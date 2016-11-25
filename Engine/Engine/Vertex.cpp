#include "stdafx.h"

#include "Vertex.h"

Vertex::Vertex() :Vertex(vec3(), vec3(), vec2(), vec3(), vec3()){
}

Vertex::Vertex(vec3 pos, vec3 n, vec2 uv, vec3 t, vec3 bT) {
    this->position = pos;
    this->normal = n.normalize();
    this->uv = uv;
    this->tangent = t.normalize();
    this->bitangent = bT.normalize();
}