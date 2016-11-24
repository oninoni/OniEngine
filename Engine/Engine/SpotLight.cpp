#include "stdafx.h"

#include "Shader.h"

#include "SpotLight.h"

SpotLight::SpotLight(vec3 d, float cO, float cOB, vec3 p, float r, vec3 c, float i) : PointLight(p, r, c, i) {
    direction = d.normalize();
    cutoff = cO;
    cutoffBlend = cOB;
}

SpotLight::SpotLight(vec3 d, float cO, float cOB, vec3 p, float r, vec3 c, float i, float ac, float al, float as) : PointLight(p ,r, c, i, ac, al, as){
    direction = d.normalize();
    cutoff = cO;
    cutoffBlend = cOB;
}

void SpotLight::setUniformSpotLight(Shader * shader, string uniformLocation) {
    setUniformPointLight(shader, uniformLocation + ".pointLight");
    shader->setUniformVec3(uniformLocation + ".l_direction", direction);
    shader->setUniformF(uniformLocation + ".l_cutoff", cutoff);
    shader->setUniformF(uniformLocation + ".l_cutoffBlend", cutoffBlend);
}

vec3 SpotLight::getDirection() {
    return direction;
}

void SpotLight::setDirection(vec3 d) {
    direction = d.normalize();
}

float SpotLight::getCutoff() {
    return cutoff;
}

void SpotLight::setCutoff(float c) {
    cutoff = c;
}

float SpotLight::getCutoffBlend() {
    return cutoffBlend;
}

void SpotLight::setCutoffBlend(float cOB) {
    cutoffBlend;
}