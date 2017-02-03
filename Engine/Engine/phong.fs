#version 430

in vec3 f_position;
in vec3 f_normal;
in vec2 f_uv;
in mat3 TBN;

in vec3 f_cameraPosition;

#include "uniforms.hs"
#include "lighting.hs"

out vec4 out_color;

void main(){
    vec3 directionToEye = normalize(f_cameraPosition - f_position);
    vec2 uvDisplaced = f_uv + ((TBN * directionToEye).xy * (texture(f_materialTexture, vec3(f_uv, 3)).r) * f_dispMapScale) + f_dispMapBias;
    
    out_color = /*texture(f_materialTexture, vec3(uvDisplaced, 0)) */ f_color * vec4(l_ambient, 1);
    
    for(int i = 0; i < l_directionalLightCount; i++){
        if(length(l_directionalLights[i].base.l_color) > 0)
            out_color += calcDirectionalLightShadowed(l_directionalLights[i], uvDisplaced);
    }
    for(int i = 0; i < l_pointLightCount; i++){
        if(length(l_pointLights[i].base.l_color) > 0)
            out_color += calcPointLight(l_pointLights[i], uvDisplaced);
    }
    for(int i = 0; i < l_spotLightCount; i++){
        if(length(l_spotLights[i].pointLight.base.l_color) > 0)
           out_color += calcSpotLightShadowed(l_spotLights[i], uvDisplaced);
    }
}