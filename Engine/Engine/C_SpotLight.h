#pragma once

class SpotLight;

#include "GameComponent.h"

class C_SpotLight : public GameComponent {
private:
    bool init;
    
    SpotLight* spotLight;
    LightHandler* lightHandler;
public:
    C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i);
    C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    void c_update(const double & delta, InputManager* input);
    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};