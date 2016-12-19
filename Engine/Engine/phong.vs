#version 430

uniform mat4 model;
uniform mat4 view;

uniform mat4 modelViewProjection;

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_uv;
layout(location = 3) in vec3 v_tangent;
layout(location = 4) in vec3 v_biTangent;

out vec3 f_position;
out vec3 f_normal;
out vec2 f_uv;
out mat3 TBN;

out vec3 f_cameraPosition;

void main(){
    f_position = vec3(vec4(v_position, 1) * model);
    f_uv = v_uv;
    
    vec3 t = normalize(vec3(vec4(v_tangent, 0) * model));
    vec3 b = normalize(vec3(vec4(v_biTangent, 0) * model));
    vec3 n = normalize(vec3(vec4(v_normal, 0) * model));
    
    f_normal = n;
    
    TBN = mat3(
        t,
        b,
        n
    );
    
    f_cameraPosition = - (view * transpose(view)[3]).xyz;
    
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
}