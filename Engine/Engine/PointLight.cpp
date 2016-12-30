#include "stdafx.h"

#include "LightHandler.h"

#include "PointLight.h"

PointLight::PointLight(GameComponent* component, vec3 color, float radius) : BaseLight(component, color), Attenuation(radius) {
    this->position = vec3(0, 0, 0);
    this->positionChanged = true;

    this->range = radius;
    this->rangeChanged = true;
}

PointLight::PointLight(GameComponent* component, vec3 color, float radius, float constant, float linear, float square) : BaseLight(component, color), Attenuation(constant, linear, square){
    this->position = vec3(0, 0, 0);
    this->positionChanged = true;

    this->range = radius;
    this->rangeChanged = true;
}

void PointLight::setUniformPointLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updatePointLight(this, 0 * sizeof(float), 12, &(color * intensity));
        colorChanged = false;
    }
    if (shadowMapIDChanged) {
        lightHandler->updatePointLight(this, 3 * sizeof(float), 4, &shadowMapID);
        shadowMapIDChanged = false;
    }
    if (constantChanged) {
        lightHandler->updatePointLight(this, 4 * sizeof(float), 4, &constant);
        constantChanged = false;
    }
    if (linearChanged) {
        lightHandler->updatePointLight(this, 5 * sizeof(float), 4, &linear);
        linearChanged = false;
    }
    if (squareChanged) {
        lightHandler->updatePointLight(this, 6 * sizeof(float), 4, &square);
        squareChanged = false;
    }
    if (positionChanged) {
        lightHandler->updatePointLight(this, 8 * sizeof(float), 12, &position);
        positionChanged = true;
    }
    if (rangeChanged) {
        lightHandler->updatePointLight(this, 11 * sizeof(float), 4, &range);
        rangeChanged = false;
    }
}

vec3 PointLight::getPosition() {
    return position;
}

void PointLight::setPosition(vec3 position) {
    if (this->position == position)return;

    this->position = position;
    positionChanged = true;
}

float PointLight::getRange() {
    return range;
}

void PointLight::setRange(float radius) {
    if (this->range == radius)return;

    this->range = radius;
    rangeChanged = true;
}

void PointLight::forceUpdate() {
    BaseLight::forceUpdate();
    Attenuation::forceUpdate();
    positionChanged = true;
    rangeChanged = true;
}