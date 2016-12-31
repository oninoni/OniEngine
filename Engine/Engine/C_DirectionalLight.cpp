#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "DirectionalLight.h"

#include "C_DirectionalLight.h"

C_DirectionalLight::C_DirectionalLight(vec3 color, bool shadowMapEnabled) {
    directionalLight = new DirectionalLight(this, color, vec3(0, 0, 0));
    if (shadowMapEnabled)
        directionalLight->setShadowMapID(-2);
    init = true;
}

void C_DirectionalLight::setShadowMapID(int shadowMapID) {
    directionalLight->setShadowMapID(shadowMapID);
}

int C_DirectionalLight::getShadowMapID() {
    return directionalLight->getShadowMapID();
}

void C_DirectionalLight::setColor(vec3 color) {
    directionalLight->setColor(color);
}

vec3 C_DirectionalLight::getColor() {
    return directionalLight->getColor();
}

void C_DirectionalLight::setIntensity(float intensity) {
    directionalLight->setIntensity(intensity);
}

float C_DirectionalLight::getIntensity() {
    return directionalLight->getIntensity();
}

void C_DirectionalLight::c_update(const double & delta, InputManager * input) {
    directionalLight->setDirection((getTransformationMatrix(true) * vec4(0, 0, -1, 0)).normalize());
}

void C_DirectionalLight::c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    if (init) {
        this->lightHandler = lightHandler;
        lightHandler->addDirectionalLight(directionalLight);
        init = false;
    }
    directionalLight->setUniformDirectionalLight(lightHandler);

    if (directionalLight->getShadowMapID() == -2)
        lightHandler->registerShadowmapDirectionalLight(directionalLight);
}

void C_DirectionalLight::c_destroy() {
    lightHandler->removeDirectionalLight(directionalLight);
    delete directionalLight;
}