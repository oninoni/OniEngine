#include "Vertex.h"

Vertex::Vertex() :Vertex(vec3(), vec4()){

}

Vertex::Vertex(vec3 pos, vec4 col) {
    position = pos;
    color = col;
}