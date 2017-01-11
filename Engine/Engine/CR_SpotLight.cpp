#include "stdafx.h"

#include "SpotLight.h"
#include "Shader.h"
#include "LightHandler.h"

#include "CR_SpotLight.h"

CR_SpotLight::CR_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled) {
    spotLight = new SpotLight(this, color, range, cutOff);
    if (shadowMapEnabled)
        spotLight->setShadowMapID(-2);
    init = true;
}

CR_SpotLight::CR_SpotLight(vec3 color, float range, float cutOff, bool shadowMapEnabled, float ac, float al, float as) {
    spotLight = new SpotLight(this, color, range, cutOff, ac, al, as);
    if (shadowMapEnabled)
        spotLight->setShadowMapID(-2);
    init = true;
}

void CR_SpotLight::setShadowMapID(int shadowMapID) {
    spotLight->setShadowMapID(shadowMapID);
}

int CR_SpotLight::getShadowMapID() {
    return spotLight->getShadowMapID();
}

void CR_SpotLight::setColor(vec3 color) {
    spotLight->setColor(color);
}

vec3 CR_SpotLight::getColor() {
    return spotLight->getColor();
}

void CR_SpotLight::setIntensity(float intensity) {
    spotLight->setIntensity(intensity);
}

float CR_SpotLight::getIntensity() {
    return spotLight->getIntensity();
}

void CR_SpotLight::c_update(const double & delta, InputManager * input) {
    spotLight->setPosition(getTransformationMatrix(false).transpose()[3]);
    spotLight->setDirection((getTransformationMatrix(true) * vec4(0, 0, -1, 0)).normalize());
}

void CR_SpotLight::c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    if (init) {
        this->lightHandler = lightHandler;
        lightHandler->addSpotLight(spotLight);
        init = false;
    }
    spotLight->setUniformSpotLight(lightHandler);

    if (spotLight->getShadowMapID() == -2)
        lightHandler->registerShadowmapSpotLight(spotLight);
}

void CR_SpotLight::c_destroy() {
    lightHandler->removePointLight(spotLight);
    delete spotLight;
}