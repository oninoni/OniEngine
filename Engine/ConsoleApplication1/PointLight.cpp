#include "PointLight.h"



PointLight::PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as) :
    BaseLight(c, i),
    Attenuation(ac, al, as)
{
    position = p;
    range = r;
}

vec3 PointLight::getPosition() {
    return position;
}

void PointLight::setPosition(vec3 p) {
    position = p;
}

float PointLight::getRange() {
    return range;
}

void PointLight::setRange(float r) {
    range = r;
}
