#include "stdafx.h"

#include "LightHandler.h"

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(GameComponent* component, vec3 color, vec3 direction) : BaseLight(component, color){
    this->direction = direction.normalize();
    directionChanged = true;
}

DirectionalLight::~DirectionalLight() {
}

void DirectionalLight::setUniformDirectionalLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updateDirectionalLight(this, 0, 12, &color);
        colorChanged = false;
    }
    if (shadowMapIDChanged) {
        lightHandler->updateDirectionalLight(this, 12, 4, &shadowMapID);
        shadowMapIDChanged = false;
    }
    if (directionChanged) {
        lightHandler->updateDirectionalLight(this, 16, 12, &direction);
        directionChanged = false;
    }
}

vec3 DirectionalLight::getDirection() {
    return direction;
}

void DirectionalLight::setDirection(vec3 direction) {
    vec3 dNormalized = direction.normalize();
    if (this->direction == dNormalized)return;

    this->direction = dNormalized;
    directionChanged = true;
}

void DirectionalLight::forceUpdate() {
    BaseLight::forceUpdate();
    directionChanged = true;
}
