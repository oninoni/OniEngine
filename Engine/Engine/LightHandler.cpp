#include "stdafx.h"

#include "TextureArrayFramebuffer.h"
#include "UniformBufferObject.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

#include "GameObject.h"

#include "PerspectiveCamera.h"
#include "OrthogonalCamera.h"
#include "Shader.h"
#include "ShaderHandler.h"
#include "RenderingEngine.h"

#include "LightHandler.h"

LightHandler::LightHandler() {
    ubo = new UniformBufferObject();
    ubo->generate(sizeof(vec4) + (2 * sizeof(vec4)) * MAX_DIRECTIONAL_LIGHTS + sizeof(vec4) + (3 * sizeof(vec4)) * MAX_POINT_LIGHTS + sizeof(vec4) + (4 * sizeof(vec4)) * MAX_SPOT_LIGHTS, GL_DYNAMIC_DRAW);

    lightProjections = new UniformBufferObject();
    lightProjections->generate(sizeof(mat4) * (MAX_DIRECTIONAL_LIGHTS_SHADOWS + MAX_SPOT_LIGHTS_SHADOWS) + sizeof(vec4) * MAX_POINT_LIGHTS_SHADOWS, GL_DYNAMIC_DRAW);

    shadowMaps = new TextureArrayFramebuffer(MAX_SPOT_LIGHTS_SHADOWS + MAX_DIRECTIONAL_LIGHTS_SHADOWS, 2048, 2048, GL_DEPTH_COMPONENT, GL_DEPTH_ATTACHMENT);
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

void LightHandler::bindShader(Shader * shader) {
    ubo->bindToShader(shader, "l_lightdata");
    lightProjections->bindToShader(shader, "l_lightMatrices");
    shader->setUniformI("f_shadowMaps", 1);
    shadowMaps->bind(1);
}

void LightHandler::registerShadowmapDirectionalLight(DirectionalLight * directionalLight) {
    directionalLight->setShadowMapID(lightCameras.size());
    lightCameras.push_back(new OrthogonalCamera(-10, 10, -10, 10, -10, 10));
}

void LightHandler::registerShadowmapSpotLight(SpotLight * spotLight) {
    spotLight->setShadowMapID(lightCameras.size());
    lightCameras.push_back(new PerspectiveCamera(1.0f, 0.1f, spotLight->getRange(), spotLight->getCutoff() * 2.0f + 1.0f)); // Offset Because Border should be black
}

void LightHandler::renderShadowmaps(ShaderHandler* shaderHandler, GameObject* root) {
    for (DirectionalLight* directionalLight : directionalLights) {
        int id = directionalLight->getShadowMapID();
        if (id >= 0) {
            Camera* camera = lightCameras[id];

            camera->setViewMatrix(directionalLight->getTransformationMatrix(true));
            shadowMaps->bindFramebuffer(id);
            RenderingEngine::clearScreen();

            root->preRender(shaderHandler, this, true);
            root->render(shaderHandler, camera, true);

            lightProjections->setData(sizeof(mat4) * id, sizeof(mat4), &camera->getViewProjectionMatrix());
        }
    }

    for (SpotLight* spotLight : spotLights) {
        int id = spotLight->getShadowMapID();
        if (id >= 0) {
            Camera* camera = lightCameras[id];

            camera->setViewMatrix(spotLight->getTransformationMatrix(true));
            shadowMaps->bindFramebuffer(id);
            RenderingEngine::clearScreen();

            root->preRender(shaderHandler, this, true);
            root->render(shaderHandler, camera, true);

            lightProjections->setData(sizeof(mat4) * (MAX_DIRECTIONAL_LIGHTS_SHADOWS + id), sizeof(mat4), &camera->getViewProjectionMatrix());
        }
    }
}