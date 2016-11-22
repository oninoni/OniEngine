#pragma once

#include "stdafx.h"

class Texture;
class Shader;

//TODO: Reflection and Refraction

class Material {
private:
    Texture* ambient;
    Texture* diffuse;
    Texture* specular;
    float specularReflectance;
    float specularExponent;

    vec4 color;
public:
    Material::Material(Texture* t, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    Material(Texture* a, Texture* d, Texture* s, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    ~Material();

    Texture* getAmbient();
    Texture* getDiffuse();
    Texture* getSpecular();
    vec4 getBaseColor();

    void bind(Shader* shader, uint unit);
};