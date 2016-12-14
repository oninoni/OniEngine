#version 430

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_uv;
//layout(location = 3) in vec3 v_tangent;
//layout(location = 4) in vec3 v_biTangent;

uniform mat4 modelViewProjection;

void main(){
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
}