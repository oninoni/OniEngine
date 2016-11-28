#include "stdafx.h"

#include "UniformBufferObject.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

#include "LightHandler.h"

#include "Shader.h"

LightHandler::LightHandler() {
    ubo = new UniformBufferObject();
    ubo->generate(sizeof(vec4) + (2 * sizeof(vec4)) * MAX_DIRECTIONAL_LIGHTS + sizeof(vec4) + (3 * sizeof(vec4)) * MAX_POINT_LIGHTS + sizeof(vec4) + (4 * sizeof(vec4)) * MAX_SPOT_LIGHTS, GL_DYNAMIC_DRAW);
}

LightHandler::~LightHandler() {
}

void LightHandler::addDirectionalLight(DirectionalLight * directionalLight) {
    directionalLights.push_back(directionalLight);
    int size = directionalLights.size();
    ubo->setData(0, sizeof(int), &size);
}

void LightHandler::addPointLight(PointLight * pointLight) {
    pointLights.push_back(pointLight);
    int size = pointLights.size();
    ubo->setData(sizeof(vec4) * (1 + MAX_DIRECTIONAL_LIGHTS * 2), sizeof(int), &size);
}

void LightHandler::addSpotLight(SpotLight * spotLight) {
    spotLights.push_back(spotLight);
    int size = spotLights.size();
    ubo->setData(sizeof(vec4) * (2 + MAX_DIRECTIONAL_LIGHTS * 2 + MAX_POINT_LIGHTS * 3) , sizeof(int), &size);
}

void LightHandler::removeDirectionalLight(DirectionalLight * directionalLight) {
    directionalLights.erase(find(directionalLights.begin(), directionalLights.end(), directionalLight));
    updateAll();
}

void LightHandler::removePointLight(PointLight * pointLight) {
    pointLights.erase(find(pointLights.begin(), pointLights.end(), pointLight));
    updateAll();
}

void LightHandler::removeSpotLight(SpotLight * spotLight) {
    spotLights.erase(find(spotLights.begin(), spotLights.end(), spotLight));
    updateAll();
}

void LightHandler::updateDirectionalLight(DirectionalLight * directionalLight, int offset, int size, void * data) {
    int lightIndex = find(directionalLights.begin(), directionalLights.end(), directionalLight) - directionalLights.begin();
    int offsetCalc = sizeof(vec4) + (lightIndex * (sizeof(vec4) * 2)) + offset;

    ubo->setData(offsetCalc, size, data);
}

void LightHandler::updatePointLight(PointLight * pointLight, int offset, int size, void * data) {
    int lightIndex = find(pointLights.begin(), pointLights.end(), pointLight) - pointLights.begin();
    int offsetCalc = sizeof(vec4) + (2 * sizeof(vec4)) * MAX_DIRECTIONAL_LIGHTS + sizeof(vec4) + (lightIndex * (sizeof(vec4) * 3)) + offset;

    ubo->setData(offsetCalc, size, data);
}

void LightHandler::updateSpotLight(SpotLight * spotLight, int offset, int size, void * data) {
    int lightIndex = find(spotLights.begin(), spotLights.end(), spotLight) - spotLights.begin();
    int offsetCalc = (sizeof(vec4) * (3 + 2 * MAX_DIRECTIONAL_LIGHTS + 3 * MAX_POINT_LIGHTS)) + (lightIndex * (sizeof(vec4) * 4)) + offset;

    ubo->setData(offsetCalc, size, data);
}

void LightHandler::updateAll() {
    int dsize = directionalLights.size();
    ubo->setData(0, sizeof(int), &dsize);
    for (DirectionalLight* directionalLight : directionalLights) {
        directionalLight->forceUpdate();
    }
    int psize = pointLights.size();
    ubo->setData(sizeof(vec4) * (MAX_DIRECTIONAL_LIGHTS * 2 + 1), sizeof(int), &psize);
    for (PointLight* pointLight : pointLights) {
        pointLight->forceUpdate();
    }
    int ssize = spotLights.size();
    ubo->setData(sizeof(vec4) * (1 + MAX_DIRECTIONAL_LIGHTS * 2 + 1 + MAX_POINT_LIGHTS * 3), sizeof(int), &ssize);
    for (SpotLight* spotLight : spotLights) {
        spotLight->forceUpdate();
    }
}

void LightHandler::bindShader(Shader * shader, string name) {
    ubo->bindToShader(shader, name);
}

void LightHandler::renderShadowmaps() {
    // Rendering all the Shadowmaps!
}
