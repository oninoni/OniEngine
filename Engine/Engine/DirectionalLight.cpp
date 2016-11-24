#include "stdafx.h"

#include "LightHandler.h"

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(vec3 c, float i, vec3 d) : BaseLight(c, i){
    direction = d.normalize();
    directionChanged = true;
}

DirectionalLight::~DirectionalLight() {
}

void DirectionalLight::setUniformDirectionalLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updateDirectionalLight(this, 0, sizeof(vec3), &color);
        colorChanged = false;
    }
    if (intensityChanged) {
        lightHandler->updateDirectionalLight(this, sizeof(vec3), sizeof(float), &intensity);
        intensityChanged = false;
    }
    if (directionChanged) {
        lightHandler->updateDirectionalLight(this, sizeof(vec3) + sizeof(float), sizeof(vec3), &direction);
        directionChanged = false;
    }
}

vec3 DirectionalLight::getDirection() {
    return direction;
}

void DirectionalLight::setDirection(vec3 d) {
    vec3 dNormalized = d.normalize();
    if (dNormalized == direction)return;

    direction = dNormalized;
    directionChanged = true;
}

void DirectionalLight::forceUpdate(LightHandler* lightHandler) {
    cout << "Force Update" << endl;
    BaseLight::forceUpdate();
    directionChanged = true;

    setUniformDirectionalLight(lightHandler);
}
