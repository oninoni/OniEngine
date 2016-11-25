#include "stdafx.h"

#include "Shader.h"
#include "LightHandler.h"
#include "DirectionalLight.h"

#include "C_DirectionalLight.h"

C_DirectionalLight::C_DirectionalLight(vec3 color, float intensity, vec3 direction) {
    directionalLight = new DirectionalLight(color, intensity, direction);
    init = true;
}

void C_DirectionalLight::c_preRender(Shader * shader){
    activeShader = shader;
    if (init) {
        activeShader->getLightHandler()->addDirectionalLight(directionalLight);
        init = false;
    }
    directionalLight->setUniformDirectionalLight(activeShader->getLightHandler());
}

void C_DirectionalLight::c_destroy() {
    activeShader->getLightHandler()->removeDirectionalLight(directionalLight);
    delete directionalLight;
}