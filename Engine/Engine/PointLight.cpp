#include "stdafx.h"

#include "Shader.h"

#include "PointLight.h"

PointLight::PointLight(vec3 p, float r, vec3 c, float i) : BaseLight(c, i), Attenuation(r) {
    position = p;
    range = r;
}

PointLight::PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as) : BaseLight(c, i), Attenuation(ac, al, as){
    position = p;
    range = r;
}

void PointLight::setUniformPointLight(Shader * shader, string uniformLocation) {
    //setUniformBaseLight(shader, uniformLocation + ".base");
    setUniformAttenuation(shader, uniformLocation + ".attenuation");
    shader->setUniformVec3(uniformLocation + ".l_position", position);
    shader->setUniformF(uniformLocation + ".l_range", range);
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
