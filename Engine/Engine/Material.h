#pragma once

class TextureArray;
class Shader;

//TODO: Reflection and Refraction

class Material {
private:
    vec4 color;
    TextureArray* textures;
    float specularReflectance;
    float specularExponent;
    float displacementScale;
    float displacementBias;

    bool specularEnabled;
    bool normalMappingEnabled;
    bool displacementMappingEnabled; //TODO

    static Material* activeMaterial;
public:
    Material(TextureArray* textures, float displacementScale = 0.0f, float displacementOffset = 0.0f, float specularExponent = 8.0f, float specularReflectance = 1.0f, vec4 color = vec3(1, 1, 1));

    vec4 getBaseColor();
    void setBaseColor(vec4 color);

    void bind(Shader* shader, uint unit);
};