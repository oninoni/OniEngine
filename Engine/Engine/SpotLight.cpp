#include "stdafx.h"

#include "LightHandler.h"

#include "SpotLight.h"

SpotLight::SpotLight(GameComponent* comp, vec3 d, float cO, vec3 p, float r, vec3 c, float i) : PointLight(comp, p, r, c, i) {
    direction = d.normalize();
    directionChanged = true;
    cutoff = cO;
    cutoffChanged = true;
}

SpotLight::SpotLight(GameComponent* comp, vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as) : PointLight(comp, p ,r, c, i, ac, al, as){
    direction = d.normalize();
    directionChanged = true;
    cutoff = cO;
    cutoffChanged = true;
}

void SpotLight::setUniformSpotLight(LightHandler * lightHandler) {
    if (colorChanged) {
        lightHandler->updateSpotLight(this, 0 * sizeof(float), 12, &color);
        colorChanged = false;
    }
    if (intensityChanged) {
        lightHandler->updateSpotLight(this, 3 * sizeof(float), 4, &intensity);
        intensityChanged = false;
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

void SpotLight::setDirection(vec3 d) {
    vec3 dNormalized = d.normalize();
    if (direction == dNormalized)return;
    direction = dNormalized;
}

float SpotLight::getCutoff() {
    return cutoff;
}

void SpotLight::setCutoff(float c) {
    if (cutoff == c)return;
    cutoff = c;
}

void SpotLight::forceUpdate() {
    PointLight::forceUpdate();
    directionChanged = true;
    cutoffChanged = true;
}