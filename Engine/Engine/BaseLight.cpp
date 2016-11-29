#include "stdafx.h"

#include "LightHandler.h"
#include "GameComponent.h"

#include "BaseLight.h"

BaseLight::BaseLight(vec3 c, float i, GameComponent* comp) {
    color = c;
    colorChanged = true;
    intensity = i;
    intensityChanged = true;

    component = comp;
}

vec3 BaseLight::getColor() {
    return color;
}

void BaseLight::setColor(vec3 c) {
    if (color == c)return;
    color = c;
    colorChanged = true;
}

float BaseLight::getIntensity() {
    return intensity;
}

void BaseLight::setIntensity(float i) {
    if (intensity == i)return;
    intensity = i;
    intensityChanged = true;
}

void BaseLight::forceUpdate() {
    colorChanged = true;
    intensityChanged = true;
}

GameComponent * BaseLight::getComponent() {
    return component;
}

mat4 BaseLight::getModelMatrix() {
    return component->getTransformationMatrix();
}
