#include "stdafx.h"

#include "LightHandler.h"

#include "PointLight.h"

PointLight::PointLight(vec3 p, float r, vec3 c, float i) : BaseLight(c, i), Attenuation(r) {
    position = p;
    positionChanged = true;
    range = r;
    rangeChanged = true;
}

PointLight::PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as) : BaseLight(c, i), Attenuation(ac, al, as){
    position = p;
    positionChanged = true;
    range = r;
    rangeChanged = true;
}

void PointLight::setUniformPointLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updatePointLight(this, 0 * sizeof(float), 12, &color);
        colorChanged = false;
    }
    if (intensityChanged) {
        lightHandler->updatePointLight(this, 3 * sizeof(float), 4, &intensity);
        intensityChanged = false;
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

void PointLight::setPosition(vec3 p) {
    if (position == p)return;
    position = p;
    positionChanged = true;
}

float PointLight::getRange() {
    return range;
}

void PointLight::setRange(float r) {
    if (range == r)return;
    range = r;
    rangeChanged = true;
}

void PointLight::forceUpdate() {
    BaseLight::forceUpdate();
    Attenuation::forceUpdate();
    positionChanged = true;
    rangeChanged = true;
}