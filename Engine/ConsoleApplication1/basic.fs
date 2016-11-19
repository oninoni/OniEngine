#version 330

in vec4 f_color;
in vec3 f_position;

out vec4 out_color;

void main(){
    out_color = vec4(f_position, 1);
}