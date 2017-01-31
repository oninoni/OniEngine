#version 430

#include "vertexdata.hs"
#include "uniforms.hs"

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