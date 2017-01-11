#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "PointLight.h"

#include "CR_PointLight.h"

CR_PointLight::CR_PointLight(vec3 color, float range, bool shadowMapEnabled) {
    pointLight = new PointLight(this, color, range);
    if (shadowMapEnabled)
        cout << "Point Lights Shadows not implemented yet!" << endl;
    init = true;
}

CR_PointLight::CR_PointLight(vec3 color, float range, bool shadowMapEnabled, float ac, float al, float as) {
    pointLight = new PointLight(this, color, range, ac, al, as);
    if (shadowMapEnabled)
        cout << "Point Lights Shadows not implemented yet!" << endl;
    init = true;
}

void CR_PointLight::setColor(vec3 color) {
    pointLight->setColor(color);
}

vec3 CR_PointLight::getColor() {
    return pointLight->getColor();
}

void CR_PointLight::setIntensity(float intensity) {
    pointLight->setIntensity(intensity);
}

float CR_PointLight::getIntensity() {
    return pointLight->getIntensity();
}

void CR_PointLight::c_update(const double & delta, InputManager * input) {
    pointLight->setPosition(getTransformationMatrix(false).transpose()[3]);
}

void CR_PointLight::c_preRender(LightHandler* lightHandler, Shader* shader) {
    this->lightHandler = lightHandler;
    if (init) {
        lightHandler->addPointLight(pointLight);
        init = false;
    }
    pointLight->setUniformPointLight(lightHandler);
}

void CR_PointLight::c_destroy() {
    lightHandler->removePointLight(pointLight);
    delete pointLight;
}