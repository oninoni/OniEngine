#include "stdafx.h"

#include "LightHandler.h"

#include "SpotLight.h"

SpotLight::SpotLight(GameComponent* component, vec3 direction, float cutoff, vec3 position, float radius, vec3 color) : PointLight(component, position, radius, color) {
    this->direction = direction.normalize();
    directionChanged = true;

    this->cutoff = cutoff;
    cutoffChanged = true;
}

SpotLight::SpotLight(GameComponent* component, vec3 direction, float cutoff, vec3 position, float radius, vec3 color, float constant, float linear, float square) : PointLight(component, position, radius, color, constant, linear, square){
    this->direction = direction.normalize();
    directionChanged = true;

    this->cutoff = cutoff;
    cutoffChanged = true;
}

void SpotLight::setUniformSpotLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updateSpotLight(this, 0 * sizeof(float), 12, &(color * intensity));
        colorChanged = false;
    }
    if (shadowMapIDChanged) {
        lightHandler->updateSpotLight(this, 3 * sizeof(float), 4, &shadowMapID);
        shadowMapIDChanged = false;
    }
    if (constantChanged) {
        lightHandler->updateSpotLight(this, 4 * sizeof(float), 4, &constant);
        constantChanged = false;
    }
    if (linearChanged) {
        lightHandler->updateSpotLight(this, 5 * sizeof(float), 4, &linear);
        linearChanged = false;
    }
    if (squareChanged) {
        lightHandler->updateSpotLight(this, 6 * sizeof(float), 4, &square);
        squareChanged = false;
    }
    if (positionChanged) {
        lightHandler->updateSpotLight(this, 8 * sizeof(float), 12, &position);
        positionChanged = false;
    }
    if (rangeChanged) {
        lightHandler->updateSpotLight(this, 11 * sizeof(float), 4, &range);
        rangeChanged = false;
    }
    if (directionChanged) {
        lightHandler->updateSpotLight(this, 12 * sizeof(float), 12, &direction);
        directionChanged = false;
    }
    if (cutoffChanged) {
        lightHandler->updateSpotLight(this, 15 * sizeof(float), 4, &cutoff);
        cutoffChanged = false;
    }

}

vec3 SpotLight::getDirection() {
    return direction;
}

void SpotLight::setDirection(vec3 direction) {
    vec3 dNormalized = direction.normalize();
    if (this->direction == dNormalized)return;

    this->direction = dNormalized;
    directionChanged = true;
}

float SpotLight::getCutoff() {
    return cutoff;
}

void SpotLight::setCutoff(float c) {
    if (this->cutoff == cutoff)return;

    this->cutoff = c;
    cutoffChanged = true;
}

void SpotLight::forceUpdate() {
    PointLight::forceUpdate();
    directionChanged = true;
    cutoffChanged = true;
}