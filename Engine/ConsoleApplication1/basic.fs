#version 330

uniform sampler2D diffuse;

in vec3 f_normal;
in vec2 f_uv;

out vec4 out_color;

void main(){
    out_color = vec4(f_uv, 0, 1) + texture(diffuse, f_uv);
}