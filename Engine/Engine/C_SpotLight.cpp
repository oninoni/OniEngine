#include "stdafx.h"

#include "SpotLight.h"
#include "Shader.h"
#include "LightHandler.h"

#include "C_SpotLight.h"

C_SpotLight::C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i) {
    spotLight = new SpotLight(this, d, cO, p, r, c, i);
    init = true;
}

C_SpotLight::C_SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as) {
    spotLight = new SpotLight(this, d, cO, p, r, c, i, ac, al, as);
    init = true;
}

void C_SpotLight::c_preRender(Shader * shader) {
    activeShader = shader;
    if (init) {
        activeShader->getLightHandler()->addSpotLight(spotLight);
        init = false;
    }
    spotLight->setUniformSpotLight(activeShader->getLightHandler());
}

void C_SpotLight::c_destroy() {
    activeShader->getLightHandler()->removePointLight(spotLight);
    delete spotLight;
}
