#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "PointLight.h"

#include "C_PointLight.h"

C_PointLight::C_PointLight(vec3 color, float range, bool shadowMapEnabled) {
    pointLight = new PointLight(this, color, range);
    if (shadowMapEnabled)
        cout << "Point Lights Shadows not implemented yet!" << endl;
    init = true;
}

C_PointLight::C_PointLight(vec3 color, float range, bool shadowMapEnabled, float ac, float al, float as) {
    pointLight = new PointLight(this, color, range, ac, al, as);
    if (shadowMapEnabled)
        cout << "Point Lights Shadows not implemented yet!" << endl;
    init = true;
}

void C_PointLight::setColor(vec3 color) {
    pointLight->setColor(color);
}

vec3 C_PointLight::getColor() {
    return pointLight->getColor();
}

void C_PointLight::setIntensity(float intensity) {
    pointLight->setIntensity(intensity);
}

float C_PointLight::getIntensity() {
    return pointLight->getIntensity();
}

void C_PointLight::c_update(const double & delta, InputManager * input) {
    pointLight->setPosition(getTransformationMatrix(false).transpose()[3]);
}

void C_PointLight::c_preRender(LightHandler* lightHandler, Shader* shader) {
    this->lightHandler = lightHandler;
    if (init) {
        lightHandler->addPointLight(pointLight);
        init = false;
    }
    pointLight->setUniformPointLight(lightHandler);
}

void C_PointLight::c_destroy() {
    lightHandler->removePointLight(pointLight);
    delete pointLight;
}