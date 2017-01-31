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

layout(std140) uniform l_lightdata {
    int l_directionalLightCount;
    DirectionalLight l_directionalLights[MAX_DIRECTIONAL_LIGHTS];
    int l_pointLightCount;
    PointLight l_pointLights[MAX_POINT_LIGHTS];
    int l_spotLightCount;
    SpotLight l_spotLights[MAX_SPOT_LIGHTS];
};

layout(std140) uniform l_lightMatrices {
    mat4 l_directionalMatrices[MAX_DIRECTIONAL_LIGHTS_SHADOWS];
    mat4 l_spotMatrices[MAX_SPOT_LIGHTS_SHADOWS];
    vec3 l_pointMatrices[MAX_POINT_LIGHTS_SHADOWS];
};