#include "stdafx.h"

#include "UniformBufferObject.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

#include "LightHandler.h"

#include "Shader.h"

LightHandler::LightHandler() {
    ubo = new UniformBufferObject();
    ubo->generate(sizeof(int) * 4 + sizeof(DirectionalLightData) * MAX_DIRECTIONAL_LIGHTS, GL_STATIC_DRAW);
}

LightHandler::~LightHandler() {
}

void LightHandler::addDirectionalLight(DirectionalLight * directionalLight) {
    directionalLights.push_back(directionalLight);
    updateAll();
}

void LightHandler::addPointLight(PointLight * pointLight) {
    pointLights.push_back(pointLight);
}

void LightHandler::addSpotLight(SpotLight * spotLight) {
    spotLights.push_back(spotLight);
}

void LightHandler::removeDirectionalLight(DirectionalLight * directionalLight) {
    directionalLight->setColor(0);
    directionalLight->setIntensity(0);
    directionalLight->setDirection(0);
    updateAll();
    directionalLights.erase(find(directionalLights.begin(), directionalLights.end(), directionalLight));
}

void LightHandler::removePointLight(PointLight * pointLight) {
    pointLights.erase(find(pointLights.begin(), pointLights.end(), pointLight));
}

void LightHandler::removeSpotLight(SpotLight * spotLight) {
    spotLights.erase(find(spotLights.begin(), spotLights.end(), spotLight));
}

void LightHandler::updateDirectionalLight(DirectionalLight * directionalLight, int offset, int size, void * data) {
    int lightOffset = find(directionalLights.begin(), directionalLights.end(), directionalLight) - directionalLights.begin();
    ubo->setData(16 + offset + lightOffset * sizeof(DirectionalLightData), size, data);
}

void LightHandler::updatePointLight(PointLight * pointLight, int offset, int size, void * data) {
    int lightOffset = find(pointLights.begin(), pointLights.end(), pointLight) - pointLights.begin();
}

void LightHandler::updateSpotLight(SpotLight * spotLight, int offset, int size, void * data) {
    int lightOffset = find(spotLights.begin(), spotLights.end(), spotLight) - spotLights.begin();
}

void LightHandler::updateAll() {
    int size = directionalLights.size();
    ubo->setData(0, sizeof(int), &size);
    for (DirectionalLight* directionalLight : directionalLights) {
        directionalLight->forceUpdate(this);
    }
}

void LightHandler::bindShader(Shader * shader, string name) {
    ubo->bindToShader(shader, name);
}