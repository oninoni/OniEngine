#include "stdafx.h"

#include "SpotLight.h"
#include "Shader.h"
#include "LightHandler.h"

#include "C_SpotLight.h"

C_SpotLight::C_SpotLight(vec3 c, float r, float cO, bool shadowMapEnabled) {
    spotLight = new SpotLight(this, vec3(0, 0, 0), cO, vec3(0, 0, 0), r, c);
    if (shadowMapEnabled)
        spotLight->setShadowMapID(-2);
    init = true;
}

C_SpotLight::C_SpotLight(vec3 c, float r, float cO, bool shadowMapEnabled, float ac, float al, float as) {
    spotLight = new SpotLight(this, vec3(0, 0, 0), cO, vec3(0, 0, 0), r, c, ac, al, as);
    if (shadowMapEnabled)
        spotLight->setShadowMapID(-2);
    init = true;
}

void C_SpotLight::setShadowMapID(int shadowMapID) {
    spotLight->setShadowMapID(shadowMapID);
}

int C_SpotLight::getShadowMapID() {
    return spotLight->getShadowMapID();
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

    if (spotLight->getShadowMapID() == -2)
        lightHandler->registerShadowmapSpotLight(spotLight);
}

void C_SpotLight::c_destroy() {
    lightHandler->removePointLight(spotLight);
    delete spotLight;
}