#pragma once

class SpotLight;

#include "GameComponent.h"

class C_SpotLight : public GameComponent {
private:
    bool init;
    
    SpotLight* spotLight;
    LightHandler* lightHandler;
public:
    C_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled = false);
    C_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled, float ac, float al, float as);

    void setShadowMapID(int shadowMapID);
    int getShadowMapID();

    void setColor(vec3 color);
    vec3 getColor();

    void setIntensity(float intensity);
    float getIntensity();

    void c_update(const double & delta, InputManager* input);
    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};