#version 330

uniform sampler2D diffuse;

in vec3 f_normal;
in vec3 f_uv;

out vec4 out_color;

void main(){
    out_color = texture2D(diffuse, f_uv);
    //out_color = vec4(abs(f_normal), 1);
}