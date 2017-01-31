#version 430

#include "vertexdata.hs"
#include "uniforms.hs"

void main(){
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
}