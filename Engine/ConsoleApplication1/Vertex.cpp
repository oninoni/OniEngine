#include "Vertex.h"

Vertex::Vertex() :Vertex(vec3(), vec3(), vec2()){

}

Vertex::Vertex(vec3 pos, vec3 n, vec2 uv) {
    this->position = pos;
    this->normal = n;
    this->uv = uv;
}