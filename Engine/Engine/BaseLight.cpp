#include "stdafx.h"

#include "LightHandler.h"
#include "GameComponent.h"

#include "BaseLight.h"

BaseLight::BaseLight(GameComponent* component, vec3 color) {
    this->color = color;
    this->intensity = 1;
    this->colorChanged = true;

    this->shadowMapID = -1;
    this->shadowMapIDChanged = true;

    this->component = component;
}

vec3 BaseLight::getColor() {
    return color;
}

void BaseLight::setColor(vec3 color) {
    if (this->color == color)return;

    this->color = color;
    colorChanged = true;
}

float BaseLight::getIntensity() {
    return intensity;
}

void BaseLight::setIntensity(float intensity) {
    if (this->intensity == intensity)return;

    this->intensity = intensity;
    colorChanged = true;
}

int BaseLight::getShadowMapID() {
    return shadowMapID;
}

void BaseLight::setShadowMapID(int shadowMapID) {
    if (this->shadowMapID == shadowMapID)return;

    this->shadowMapID = shadowMapID;
    shadowMapIDChanged = true;
}

void BaseLight::forceUpdate() {
    colorChanged = true;
    shadowMapIDChanged = true;
}

mat4 BaseLight::getTransformationMatrix(bool inverted) {
    return component->getTransformationMatrix(inverted);
}