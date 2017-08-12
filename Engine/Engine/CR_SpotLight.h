#pragma once

class SpotLight;

#include "GameProperty.h"

class CR_SpotLight : public GameProperty {
private:
    bool init;
    
    SpotLight* spotLight;
    LightHandler* lightHandler;
public:
    CR_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled = false);
    CR_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled, float ac, float al, float as);

    void setShadowMapID(int shadowMapID);
    int getShadowMapID();

    void setColor(vec3 color);
    vec3 getColor();

    void setIntensity(float intensity);
    float getIntensity();

    void c_update(const double & delta, InputManager* input);
    void c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender = false);
    void c_destroy();
};