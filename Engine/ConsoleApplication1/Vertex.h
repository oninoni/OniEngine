#pragma once

#include "m_vector.h"

class Vertex {
private:
    vec3 position;
public:
    Vertex(vec3 pos);
    ~Vertex();

    vec3 getPosition();
    void setPosition(vec3 pos);
};