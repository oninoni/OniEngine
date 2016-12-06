#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "PointLight.h"

#include "C_PointLight.h"

C_PointLight::C_PointLight(vec3 p, float r, vec3 c, float i) {
    pointLight = new PointLight(this, p, r, c, i);
    init = true;
}

C_PointLight::C_PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as) {
    pointLight = new PointLight(this, p, r, c, i, ac, al, as);
    init = true;
}

void C_PointLight::c_preRender(LightHandler* lightHandler, Shader* shader) {
    this->lightHandler = lightHandler;
    if (init) {
        lightHandler->addPointLight(pointLight);
        init = false;
    }
    pointLight->setUniformPointLight(lightHandler);
}

void C_PointLight::c_destroy() {
    lightHandler->removePointLight(pointLight);
    delete pointLight;
}