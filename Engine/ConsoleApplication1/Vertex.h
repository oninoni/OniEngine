#pragma once

#include "stdafx.h"

/*
Postion vec3
Normal vec3
uv vec2
color vec3
uvector/tangent vec3
vvector/bitangent vec3

Material:

ambientTexture sampler2D
diffuseTexture sampler2D
specularTexture sampler2D
*/

class Vertex {
public:
    Vertex();
    Vertex(vec3 pos, vec3 n, vec2 uv);

    vec3 position;
    vec3 normal;
    vec2 uv;
};