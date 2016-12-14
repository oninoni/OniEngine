#pragma once

class PhongShader;
class ShadowmapShader;

class ShaderHandler {
private:
    PhongShader* phongShader;
    ShadowmapShader* shadowmapShader;
public:
    ShaderHandler();
    ~ShaderHandler();

    PhongShader* getPhongShader();
    ShadowmapShader* getShadowmapShader();

    uint getCount();
    Shader* getShader(uint id);
};