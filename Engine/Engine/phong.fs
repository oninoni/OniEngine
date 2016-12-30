#version 430

const int MAX_DIRECTIONAL_LIGHTS = 4;
const int MAX_POINT_LIGHTS = 64;
const int MAX_SPOT_LIGHTS = 64;

const int MAX_DIRECTIONAL_LIGHTS_SHADOWS = 4;
const int MAX_POINT_LIGHTS_SHADOWS = 16;
const int MAX_SPOT_LIGHTS_SHADOWS = 32;

const float SHADOWMAP_TEXEL_SIZE = 1.0 / 2048.0;

struct BaseLight{
    vec3 l_color;
    int l_shadowMapID;
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
};

uniform sampler2DArray f_materialTexture;
uniform sampler2DArrayShadow f_shadowMaps;

uniform vec4 f_color;
uniform float f_specularReflectance;
uniform float f_specularExponent;
uniform float f_dispMapScale;
uniform float f_dispMapBias;

layout (std140) uniform l_lightdata{
    int l_directionalLightCount;
    DirectionalLight l_directionalLights[MAX_DIRECTIONAL_LIGHTS];
    int l_pointLightCount;
    PointLight l_pointLights[MAX_POINT_LIGHTS];
    int l_spotLightCount;
    SpotLight l_spotLights[MAX_SPOT_LIGHTS];
};

layout (std140) uniform l_lightMatrices{
    mat4 l_directionalMatrices[MAX_DIRECTIONAL_LIGHTS_SHADOWS];
    mat4 l_spotMatrices[MAX_SPOT_LIGHTS_SHADOWS];
    vec3 l_pointMatrices[MAX_POINT_LIGHTS_SHADOWS];
};

uniform vec3 l_ambient;

in vec3 f_position;
in vec3 f_normal;
in vec2 f_uv;

in mat3 TBN;

in vec3 f_cameraPosition;

out vec4 out_color;

float calcPCFShadow(vec2 coords, int layer, float compare){
    int level = 1;
    float compare2 = compare - level * SHADOWMAP_TEXEL_SIZE;
    float partCount = pow(level * 2 + 1, 2);
    if(level <= 0)return texture(f_shadowMaps, vec4(coords, layer, compare));
    float shadowFactor = 0.0f;
    for(int x = -level; x <= level; x++){
        for(int y = -level; y <= level; y++){
            vec2 texelPos = vec2(
                coords.x + x * SHADOWMAP_TEXEL_SIZE,
                coords.y + y * SHADOWMAP_TEXEL_SIZE
            );
            shadowFactor += texture(f_shadowMaps, vec4(texelPos, layer, compare2)) / partCount;
        }
    }
    return shadowFactor;
}

float calcShadow(vec3 shadowMapPos, vec3 lightVec, int shadowID){
    float shadowFactor = 1;
    
    if(shadowMapPos.x >= 0 && shadowMapPos.x <= 1 && 
        shadowMapPos.y >= 0 && shadowMapPos.y <= 1 && 
        shadowMapPos.z >= 0 && shadowMapPos.z <= 1){
        float cosTheta = dot(f_normal, normalize(-lightVec));
        if(cosTheta > 0){
            float bias = 1e-3 / length(lightVec) * max(1, tan(acos(cosTheta)));
            //float bias = 2 * SHADOWMAP_TEXEL_SIZE / length(lightVec) * max(1, tan(acos(cosTheta)));
            shadowFactor = calcPCFShadow(shadowMapPos.xy, shadowID, shadowMapPos.z - bias);
            if (cosTheta < 5e-2)
                shadowFactor *= cosTheta / 5e-2;
        }else{
            shadowFactor = 0;
        }
    }
    
    return shadowFactor;
}

vec4 calcLight(BaseLight base, vec3 direction, vec2 uvDisplaced){
    vec3 f_normal = normalize(TBN * (texture(f_materialTexture, vec3(uvDisplaced, 2)).rgb * 2.0 - 1.0));
    
    float diffuseFactor = dot(-direction, f_normal);
    
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    vec4 specularColor = vec4(0, 0, 0, 0);
    
    if(diffuseFactor > 0){
        diffuseColor = texture(f_materialTexture, vec3(uvDisplaced, 0)) * f_color * vec4(base.l_color, 1.0) * diffuseFactor;
        
        vec3 directionToEye = normalize(f_cameraPosition - f_position);
        vec3 reflectedDirection = reflect(direction, f_normal);
        
        float specularFactor = dot(directionToEye, reflectedDirection);
        
        if(specularFactor > 0){
            specularFactor = pow(specularFactor, f_specularExponent);
            specularColor = texture(f_materialTexture, vec3(uvDisplaced, 1)) * f_specularReflectance * f_color * vec4(base.l_color, 1.0) * specularFactor;
        }
    }
    
    return diffuseColor + specularColor;
}

vec4 calcDirectionalLightShadowed(DirectionalLight dLight, vec2 uvDisplaced){
    int shadowID = dLight.base.l_shadowMapID;
    if(shadowID >= 0){
        vec4 shadowMapPosTemp = vec4(f_position, 1.0) * l_directionalMatrices[shadowID];
        vec3 shadowMapPos = (shadowMapPosTemp.xyz / shadowMapPosTemp.w) * 0.5 + 0.5;
        
        return calcLight(dLight.base, dLight.l_direction, uvDisplaced) *
            calcShadow(shadowMapPos, dLight.l_direction, shadowID);
    }
    return calcLight(dLight.base, dLight.l_direction, uvDisplaced);
}

vec4 calcPointLight(PointLight pointLight, vec2 uvDisplaced){
    vec3 direction = f_position - pointLight.l_position;
    float distanceToLight = length(direction);
    
    if(distanceToLight > pointLight.l_range*2)
        return vec4(0, 0, 0, 0);
    
    direction = normalize(direction);
    
    vec4 color = calcLight(pointLight.base, direction, uvDisplaced);
    
    float attenuation = 
            pointLight.attenuation.attend_constant + 
            pointLight.attenuation.attend_linear * distanceToLight + 
            pointLight.attenuation.attend_square * (distanceToLight * distanceToLight);
    
    return color / attenuation;
}

vec4 calcSpotLight(SpotLight spotLight, vec2 uvDisplaced){
    vec3 direction = normalize(f_position - spotLight.pointLight.l_position);
    float angle = acos(dot(spotLight.l_direction, direction)) * 180 / 3.14159265359;
    
    vec4 color = vec4(0, 0, 0, 0);
    
    int l_cutoffBlend = 5;
    if(angle < spotLight.l_cutoff){
        float multiplier = 1;
        if(spotLight.l_cutoff - l_cutoffBlend < angle){
            multiplier = 1 - (angle - (spotLight.l_cutoff - l_cutoffBlend)) / l_cutoffBlend;
        }
        color = calcPointLight(spotLight.pointLight, uvDisplaced) * multiplier;
    }
    
    return color;
}

vec4 calcSpotLightShadowed(SpotLight spotLight, vec2 uvDisplaced){
    int shadowID = spotLight.pointLight.base.l_shadowMapID;
    if(shadowID >= 0){
        vec4 shadowMapPosTemp = vec4(f_position, 1.0) * l_spotMatrices[shadowID];
        vec3 shadowMapPos = (shadowMapPosTemp.xyz / shadowMapPosTemp.w) * 0.5 + 0.5;
        
        return calcSpotLight(spotLight, uvDisplaced) *
            calcShadow(shadowMapPos, f_position - spotLight.pointLight.l_position, shadowID);
    }
    return calcSpotLight(spotLight, uvDisplaced);
}

void main(){
    vec3 directionToEye = normalize(f_cameraPosition - f_position);
    vec2 uvDisplaced = f_uv + ((TBN * directionToEye).xy * (texture(f_materialTexture, vec3(f_uv, 3)).r) * f_dispMapScale) + f_dispMapBias;
    
    out_color = texture(f_materialTexture, vec3(uvDisplaced, 0)) * f_color * vec4(l_ambient, 1);
    
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