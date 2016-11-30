#pragma once

class DirectionalLight;
class PointLight;
class SpotLight;

class TextureArrayFramebuffer;
class UniformBufferObject;

class GameObject;

class Shader;

class LightHandler {
private:
    const int MAX_DIRECTIONAL_LIGHTS = 4;
    const int MAX_POINT_LIGHTS = 64;
    const int MAX_SPOT_LIGHTS = 64;

    UniformBufferObject* ubo;
    UniformBufferObject* lightProjections;

    vector<DirectionalLight*> directionalLights;
    vector<PointLight*> pointLights;
    vector<SpotLight*> spotLights;
public:
    LightHandler();
    ~LightHandler();

    void addDirectionalLight(DirectionalLight* directionalLight);
    void addPointLight(PointLight* pointLight);
    void addSpotLight(SpotLight* spotLight);

    void removeDirectionalLight(DirectionalLight* directionalLight);
    void removePointLight(PointLight* pointLight);
    void removeSpotLight(SpotLight* spotLight);

    void updateDirectionalLight(DirectionalLight* directionalLight, int offset, int size, void* data);
    void updatePointLight(PointLight* pointLight, int offset, int size, void* data);
    void updateSpotLight(SpotLight* spotLight, int offset, int size, void* data);

    void updateAll();

    void bindShader(Shader* shader);

    void renderShadowmaps(Shader* shader, GameObject* root);

    static TextureArrayFramebuffer* shadowMaps;
};