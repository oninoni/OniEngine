#include "lightingConstants.hs"
#include "lightingUniforms.hs"

float calcPCFShadow(int shadowID){
    int level = 0;
    vec4 shadowMapPosTemp = vec4(f_position + f_normal * SHADOWMAP_TEXEL_SIZE * 16, 1.0) * l_Matrices[shadowID];
    vec3 shadowMapPos = (shadowMapPosTemp.xyz / shadowMapPosTemp.w) * 0.5 + 0.5;

    if(level <= 0)return texture(f_shadowMaps, vec4(shadowMapPos.xy, shadowID, shadowMapPos.z));
    float partCount = pow(level * 2 + 1, 2);
    float shadowFactor = 0.0f;
    for(int x = -level; x <= level; x++){
        for(int y = -level; y <= level; y++){
            vec2 texelPos = vec2(
                shadowMapPos.x + x * SHADOWMAP_TEXEL_SIZE,
                shadowMapPos.y + y * SHADOWMAP_TEXEL_SIZE
            );
			shadowFactor += texture(f_shadowMaps, vec4(texelPos, shadowID, shadowMapPos.z)) / partCount;
        }
    }
    return shadowFactor;
}

float calcShadow(vec3 lightVec, int shadowID){
    float shadowFactor = 1;
    
    vec4 shadowMapPosTemp = vec4(f_position - f_normal * SHADOWMAP_TEXEL_SIZE, 1.0) * l_Matrices[shadowID];
    vec3 shadowMapPos = (shadowMapPosTemp.xyz / shadowMapPosTemp.w) * 0.5 + 0.5;
	
    if(shadowMapPos.x >= 0 && shadowMapPos.x <= 1 && 
        shadowMapPos.y >= 0 && shadowMapPos.y <= 1 && 
        shadowMapPos.z >= 0 && shadowMapPos.z <= 1){
        float cosTheta = dot(f_normal, normalize(-lightVec));
        if(cosTheta > 0){
            shadowFactor = calcPCFShadow(shadowID);
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

vec4 calcPointLight(PointLight pointLight, vec2 uvDisplaced){
    vec3 direction = f_position - pointLight.l_position;
    float distanceToLight = length(direction);
    
    if(distanceToLight > pointLight.l_range)
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

vec4 calcDirectionalLightShadowed(DirectionalLight dLight, vec2 uvDisplaced){
    int shadowID = dLight.base.l_shadowMapID;
    if(shadowID >= 0){
        return calcLight(dLight.base, dLight.l_direction, uvDisplaced) *
            calcShadow(dLight.l_direction, shadowID);
    }
    return calcLight(dLight.base, dLight.l_direction, uvDisplaced);
}

vec4 calcSpotLightShadowed(SpotLight spotLight, vec2 uvDisplaced){
    int shadowID = spotLight.pointLight.base.l_shadowMapID;
    if(shadowID >= 0){
        return calcSpotLight(spotLight, uvDisplaced) *
            calcShadow(f_position - spotLight.pointLight.l_position, shadowID);
    }
    return calcSpotLight(spotLight, uvDisplaced);
}
