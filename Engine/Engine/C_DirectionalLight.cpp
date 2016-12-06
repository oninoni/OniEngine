#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "DirectionalLight.h"

#include "C_DirectionalLight.h"

C_DirectionalLight::C_DirectionalLight(vec3 color, float intensity, vec3 direction) {
    directionalLight = new DirectionalLight(this, color, intensity, direction);
    init = true;
}

void C_DirectionalLight::c_preRender(LightHandler* lightHandler, Shader * shader) {
    this->lightHandler = lightHandler;
    if (init) {
        lightHandler->addDirectionalLight(directionalLight);
        init = false;
    }
    directionalLight->setUniformDirectionalLight(lightHandler);
}

void C_DirectionalLight::c_destroy() {
    lightHandler->removeDirectionalLight(directionalLight);
    delete directionalLight;
}