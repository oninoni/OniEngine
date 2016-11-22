#include "DirectionalLight.h"

#include "BaseLight.h"

DirectionalLight::DirectionalLight(vec3 c, float i, vec3 d) : BaseLight(c, i){
    direcion = d.normalize();
}

DirectionalLight::~DirectionalLight() {
}

vec3 DirectionalLight::getDirection() {
    return direcion;
}

void DirectionalLight::setDirection(vec3 d) {
    direcion = d.normalize();
}
