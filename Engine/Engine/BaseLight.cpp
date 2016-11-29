#include "stdafx.h"

#include "LightHandler.h"
#include "GameComponent.h"

#include "BaseLight.h"

BaseLight::BaseLight(GameComponent* component, vec3 color, float intensity) {
    this->color = color;
    this->colorChanged = true;

    this->intensity = intensity;
    this->intensityChanged = true;

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
    intensityChanged = true;
}

void BaseLight::forceUpdate() {
    colorChanged = true;
    intensityChanged = true;
}

mat4 BaseLight::getTransformationMatrix(bool inverted) {
    return component->getTransformationMatrix(inverted);
}