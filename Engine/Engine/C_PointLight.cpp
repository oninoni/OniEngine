#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "PointLight.h"

#include "C_PointLight.h"

C_PointLight::C_PointLight(vec3 p, float r, vec3 c, float i) {
    pointLight = new PointLight(p, r, c, i);
    init = true;
}

C_PointLight::C_PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as) {
    pointLight = new PointLight(p, r, c, i, ac, al, as);
    init = true;
}

void C_PointLight::c_preRender(Shader * shader) {
    activeShader = shader;
    if (init) {
        activeShader->getLightHandler()->addPointLight(pointLight);
        init = false;
    }
    pointLight->setUniformPointLight(activeShader->getLightHandler());
}

void C_PointLight::c_destroy() {
    activeShader->getLightHandler()->removePointLight(pointLight);
    delete pointLight;
}