#include "stdafx.h"

#include "LightHandler.h"

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(GameComponent* comp, vec3 c, float i, vec3 d) : BaseLight(c, i, comp){
    direction = d.normalize();
    directionChanged = true;
}

DirectionalLight::~DirectionalLight() {
}

void DirectionalLight::setUniformDirectionalLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updateDirectionalLight(this, 0, 12, &color);
        colorChanged = false;
    }
    if (intensityChanged) {
        lightHandler->updateDirectionalLight(this, 12, 4, &intensity);
        intensityChanged = false;
    }
    if (directionChanged) {
        lightHandler->updateDirectionalLight(this, 16, 12, &direction);
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

void DirectionalLight::forceUpdate() {
    BaseLight::forceUpdate();
    directionChanged = true;
}
