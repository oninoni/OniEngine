#version 420

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 modelViewProjection;

in vec3 v_position;
in vec3 v_normal;
in vec2 v_uv;

out vec3 f_normal;
out vec2 f_uv;  
out vec3 f_position;

void main(){
    f_normal = normalize(v_normal);
    f_uv = v_uv;
    f_position = vec3(vec4(v_position, 1) * model);
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
}