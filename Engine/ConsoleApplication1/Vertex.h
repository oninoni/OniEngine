#pragma once

#include "m_vector.h"

/*
Postion vec3
Normal vec3
color vec3
uv vec2
ka
kd
ks
*/

struct Vertex {
    Vertex(vec3 pos, vec4 col);

    vec3 position;
    vec4 color;
};