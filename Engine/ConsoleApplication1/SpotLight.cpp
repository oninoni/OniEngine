#include "SpotLight.h"

SpotLight::SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as) : PointLight(p ,r, c, i, ac, al, as){
    direction = d;
    direction.normalize();
    cutoff = cO;
}

vec3 SpotLight::getDirection() {
    return direction;
}

void SpotLight::setDirection(vec3 d) {
    direction = d;
    direction.normalize();
}

float SpotLight::getCutoff() {
    return cutoff;
}

void SpotLight::setCutoff(float c) {
    cutoff = c;
}
