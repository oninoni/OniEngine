#pragma once

class DirectionalLight;
class PointLight;
class SpotLight;

class TextureArrayFramebuffer;
class UniformBufferObject;

class GameObject;

class Camera;

class ShaderHandler;
class Shader;

class LightHandler {
private:
    const int MAX_DIRECTIONAL_LIGHTS = 4;
    const int MAX_SPOT_LIGHTS = 64;
    const int MAX_POINT_LIGHTS = 64;

    const int MAX_DIRECTIONAL_LIGHTS_SHADOWS = 4;
    const int MAX_SPOT_LIGHTS_SHADOWS = 32;
    const int MAX_POINT_LIGHTS_SHADOWS = 16;

    UniformBufferObject* ubo;
    UniformBufferObject* lightProjections;

    vector<DirectionalLight*> directionalLights;
    vector<SpotLight*> spotLights;
    vector<PointLight*> pointLights;

    vector<Camera*> lightCameras;

    TextureArrayFramebuffer* shadowMaps;
public:
    LightHandler();
    ~LightHandler();

    void addDirectionalLight(DirectionalLight* directionalLight);
    void addSpotLight(SpotLight* spotLight);
    void addPointLight(PointLight* pointLight);

    void removeDirectionalLight(DirectionalLight* directionalLight);
    void removeSpotLight(SpotLight* spotLight);
    void removePointLight(PointLight* pointLight);

    void updateDirectionalLight(DirectionalLight* directionalLight, int offset, int size, void* data);
    void updateSpotLight(SpotLight* spotLight, int offset, int size, void* data);
    void updatePointLight(PointLight* pointLight, int offset, int size, void* data);

    void updateAll();

    void bindShader(Shader* shader);

    void registerShadowmapDirectionalLight(DirectionalLight* spotLight);
    void registerShadowmapSpotLight(SpotLight* spotLight);

    void renderShadowmaps(ShaderHandler* shaderHandler, GameObject* root);

    static TextureArrayFramebuffer* shadowMapsSpotLights;
};