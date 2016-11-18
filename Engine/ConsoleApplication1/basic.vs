#version 330

uniform mat4 mvp;

in vec3 v_position;
in vec4 v_color;

out vec4 f_color;

void main(){
    f_color = v_color;
    gl_Position = vec4(v_position, 1.0) * mvp;
}