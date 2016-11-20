#version 330

uniform mat4 mvp;

in vec3 v_position;
in vec3 v_normal;
in vec2 v_uv;

out vec3 f_normal;
out vec2 f_uv;

void main(){
    f_normal = v_normal;
    f_uv = v_uv;
    gl_Position = vec4(v_position, 1.0) * mvp;
}