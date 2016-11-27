#version 430

uniform mat4 model;
uniform mat4 view;

uniform mat4 modelViewProjection;

in vec3 v_position;
in vec3 v_normal;
in vec2 v_uv;
in vec3 v_tangent;
in vec3 v_biTangent;

out vec3 f_position;
out vec2 f_uv;
out mat3 TBN;

out vec3 f_cameraPosition;

void main(){
    f_position = vec3(vec4(v_position, 1) * model);
    f_uv = v_uv;
    
    vec3 t = normalize(vec3(vec4(v_tangent, 0) * model));
    vec3 b = normalize(vec3(vec4(v_biTangent, 0) * model));
    vec3 n = normalize(vec3(vec4(v_normal, 0) * model));
    
    TBN = mat3(
        t,
        b,
        n
    );
    
    f_cameraPosition = - (view * transpose(view)[3]).xyz;
    
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
}