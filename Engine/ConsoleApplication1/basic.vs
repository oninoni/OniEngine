#version 330

uniform mat4 mvp;

in vec3 v_position;
in vec4 v_color;

out vec4 f_color;
out vec3 f_position;

void main(){
    f_color = v_color;
    f_position = v_position;
    gl_Position = vec4(v_position, 1.0) * mvp;
}