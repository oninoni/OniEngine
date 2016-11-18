#pragma once

#include "m_vector.h"

class Vertex {
private:
    vec3 position;
public:
    static const int SIZE;

    Vertex(vec3 pos);
    ~Vertex();

    vec3 getPosition();
    void setPosition(vec3 pos);
};