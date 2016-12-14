#version 430

const int MAX_DIRECTIONAL_LIGHTS = 4;
const int MAX_POINT_LIGHTS = 64;
const int MAX_SPOT_LIGHTS = 64;

uniform mat4 model;
uniform mat4 view;

uniform mat4 modelViewProjection;

layout (std140) uniform l_lightMatrices{
    mat4 l_directionalMatrices[MAX_DIRECTIONAL_LIGHTS];
    mat4 l_pointMatrices[MAX_POINT_LIGHTS];
    mat4 l_spotMatrices[MAX_SPOT_LIGHTS];
};

in vec3 v_position;
in vec3 v_normal;
in vec2 v_uv;
in vec3 v_tangent;
in vec3 v_biTangent;

out vec3 f_position;
out vec2 f_uv;
out mat3 TBN;

out vec3 shadowPosSpot[MAX_SPOT_LIGHTS];

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
    
    vec4 shadowPosTemp = (vec4(v_position, 1.0) * model) * l_spotMatrices[0];
    shadowPosSpot[0] = (shadowPosTemp.xyz / shadowPosTemp.w) * 0.5 + 0.5;
    
    gl_Position = vec4(v_position, 1.0) * modelViewProjection;
    gl_Position = vec4(shadowPosTemp.xyz / shadowPosTemp.w, 1);
}