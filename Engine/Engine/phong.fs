#version 420

const int MAX_DIRECTIONAL_LIGHTS = 4;
const int MAX_POINT_LIGHTS = 64;
const int MAX_SPOT_LIGHTS = 64;

struct BaseLight{
    vec3 l_color;
    float l_intensity;
};

struct Attenuation{
    float attend_constant;
    float attend_linear;
    float attend_square;
};

struct DirectionalLight{
    BaseLight base;
    vec3 l_direction;
};

struct PointLight{
    BaseLight base;
    Attenuation attenuation;
    vec3 l_position;
    float l_range;
};

struct SpotLight{
    PointLight pointLight;
    vec3 l_direction;
    float l_cutoff;
    float l_cutoffBlend;
};

uniform vec4 f_color;

uniform sampler2D f_ambient;
uniform vec3 l_ambient;

uniform sampler2D f_diffuse;

uniform sampler2D f_specular;
uniform float f_specularReflectance;
uniform float f_specularExponent;

uniform DirectionalLight ;
//uniform 
layout (std140) uniform l_lightdata{
    int l_directionalLightCount;
    DirectionalLight l_directionalLights[MAX_DIRECTIONAL_LIGHTS];
    //int l_pointLightCount;
    //PointLight l_pointLights[MAX_POINT_LIGHTS];
    //int l_spotLightCount;
    //SpotLight l_spotLights[MAX_SPOT_LIGHTS];
};

in vec3 f_normal;
in vec2 f_uv;
in vec3 f_position;
in vec3 f_cameraPosition;

out vec4 out_color;


vec4 calcLight(BaseLight base, vec3 direction){
    float diffuseFactor = dot(-direction, f_normal);
    
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    vec4 specularColor = vec4(0, 0, 0, 0);
    
    if(diffuseFactor > 0){
        diffuseColor = texture(f_diffuse, f_uv) * f_color * vec4(base.l_color, 1.0) * base.l_intensity * diffuseFactor;
        
        vec3 directionToEye = normalize(f_cameraPosition - f_position);
        vec3 reflectedDirection = normalize(reflect(direction, f_normal));
        
        float specularFactor = dot(directionToEye, reflectedDirection);
        
        if(specularFactor > 0){
            specularFactor = pow(specularFactor, f_specularExponent);
            specularColor = texture(f_specular, f_uv) * f_specularReflectance * f_color * vec4(base.l_color, 1.0) * base.l_intensity * specularFactor;
        }
    }
    
    return diffuseColor + specularColor;
}

vec4 calcDirectionalLight(DirectionalLight dLight){
    return calcLight(dLight.base, dLight.l_direction);
}

vec4 calcPointLight(PointLight pointLight){
    vec3 direction = f_position - pointLight.l_position;
    float distanceToLight = length(direction);
    
    if(distanceToLight > pointLight.l_range*2)
        return vec4(0, 0, 0, 0);
    
    direction = normalize(direction);
    
    vec4 color = calcLight(pointLight.base, direction);
    
    float attenuation = 
            pointLight.attenuation.attend_constant + 
            pointLight.attenuation.attend_linear * distanceToLight + 
            pointLight.attenuation.attend_square * (distanceToLight * distanceToLight);
    
    return color / attenuation;
}

vec4 calcSpotLight(SpotLight spotLight){
    vec3 direction = normalize(f_position - spotLight.pointLight.l_position);
    float angle = acos(dot(spotLight.l_direction, direction)) * 180 / 3.14159265359;
    
    vec4 color = vec4(0, 0, 0, 0);
    
    if(angle < spotLight.l_cutoff){
        float multiplier = 1;
        if(spotLight.l_cutoff - spotLight.l_cutoffBlend < angle){
            multiplier = 1 - (angle - (spotLight.l_cutoff - spotLight.l_cutoffBlend)) / spotLight.l_cutoffBlend;
        }
        color = calcPointLight(spotLight.pointLight) * multiplier;
    }
    
    return color;
}

void main(){
    out_color = texture(f_ambient, f_uv) * f_color * vec4(l_ambient, 1);
    
    for(int i = 0; i < l_directionalLightCount; i++){
        if(l_directionalLights[i].base.l_intensity > 0)
            out_color += calcDirectionalLight(l_directionalLights[i]);
    }
    //for(int i = 0; i < l_pointLightCount; i++){
    //    if(l_pointLights[i].base.l_intensity > 0)
    //        out_color += calcPointLight(l_pointLights[i]);
    //}
    //
    //for(int i = 0; i < l_spotLightCount; i++){
    //    if(l_spotLights[i].pointLight.base.l_intensity > 0)
    //        out_color += calcSpotLight(l_spotLights[i]);
    //}
}