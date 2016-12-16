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

void C_SpotLight::c_update(const double & delta, InputManager * input) {
    spotLight->setPosition(getTransformationMatrix(false).transpose()[3]);
    spotLight->setDirection((getTransformationMatrix(true) * vec4(0, 0, -1, 0)).normalize());
}

void C_SpotLight::c_preRender(LightHandler* lightHandler, Shader * shader) {
    this->lightHandler = lightHandler;
    if (init) {
        lightHandler->addSpotLight(spotLight);
        init = false;
    }
    spotLight->setUniformSpotLight(lightHandler);
}

void C_SpotLight::c_destroy() {
    lightHandler->removePointLight(spotLight);
    delete spotLight;
}