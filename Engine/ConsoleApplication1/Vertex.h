#pragma once

#include "m_vector.h"

/*
Postion vec3
Normal vec3
uv vec2
ka vec3
kd vec3
ks vec3
uvector/tangent vec3
vvector/bitangent vec3
*/

struct Vertex {
    Vertex();
    Vertex(vec3 pos, vec3 n, vec2 uv);

    vec3 position;
    vec3 normal;
    vec2 uv;
};