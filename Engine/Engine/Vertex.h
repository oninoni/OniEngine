#pragma once

/*
Postion vec3
Normal vec3
uv vec2
color vec3

Material:

ambientTexture sampler2D
diffuseTexture sampler2D
specularTexture sampler2D
*/

class Vertex {
public:
    Vertex();
    Vertex(vec3 pos, vec3 n, vec2 uv, vec3 t, vec3 bt);

    vec3 position;
    vec3 normal;
    vec2 uv;
    vec3 tangent;   //uvector/tangent
    vec3 bitangent; //vvector/bitangent
};