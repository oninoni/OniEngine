#pragma once

class SpotLight;

#include "GameComponent.h"
class C_SpotLight : public GameComponent {
private:
    bool init;
    
    SpotLight* spotLight;

    Shader* activeShader;
public:
    C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i);
    C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    void c_preRender(Shader* shader);
    void c_destroy();
};