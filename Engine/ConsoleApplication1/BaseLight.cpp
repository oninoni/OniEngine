#include "BaseLight.h"



BaseLight::BaseLight(vec3 c, float i) {
    color = c;
    intensity = i;
}

vec3 BaseLight::getColor() {
    return color;
}

void BaseLight::setColor(vec3 c) {
    color = c;
}

float BaseLight::getIntensity() {
    return intensity;
}

void BaseLight::setIntensity(float i) {
    intensity = i;
}
