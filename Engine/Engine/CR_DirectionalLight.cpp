#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "DirectionalLight.h"

#include "CR_DirectionalLight.h"

CR_DirectionalLight::CR_DirectionalLight(vec3 color, bool shadowMapEnabled) {
    directionalLight = new DirectionalLight(this, color, vec3(0, 0, 0));
    if (shadowMapEnabled)
        directionalLight->setShadowMapID(-2);
    init = true;
}

void CR_DirectionalLight::setShadowMapID(int shadowMapID) {
    directionalLight->setShadowMapID(shadowMapID);
}

int CR_DirectionalLight::getShadowMapID() {
    return directionalLight->getShadowMapID();
}

void CR_DirectionalLight::setColor(vec3 color) {
    directionalLight->setColor(color);
}

vec3 CR_DirectionalLight::getColor() {
    return directionalLight->getColor();
}

void CR_DirectionalLight::setIntensity(float intensity) {
    directionalLight->setIntensity(intensity);
}

float CR_DirectionalLight::getIntensity() {
    return directionalLight->getIntensity();
}

void CR_DirectionalLight::c_update(const double & delta, InputManager * input) {
    directionalLight->setDirection((getTransformationMatrix(true) * vec4(0, 0, -1, 0)).normalize());
}

void CR_DirectionalLight::c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    if (init) {
        this->lightHandler = lightHandler;
        lightHandler->addDirectionalLight(directionalLight);
        init = false;
    }
    directionalLight->setUniformDirectionalLight(lightHandler);

    if (directionalLight->getShadowMapID() == -2)
        lightHandler->registerShadowmapDirectionalLight(directionalLight);
}

void CR_DirectionalLight::c_destroy() {
    lightHandler->removeDirectionalLight(directionalLight);
    delete directionalLight;
}