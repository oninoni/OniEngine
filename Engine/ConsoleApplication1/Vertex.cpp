#include "Vertex.h"

const int Vertex::SIZE = 3;

Vertex::Vertex(vec3 pos) {
    position = pos;
}


Vertex::~Vertex() {

}

vec3 Vertex::getPosition() {
    return position;
}

void Vertex::setPosition(vec3 pos) {
    position = pos;
}