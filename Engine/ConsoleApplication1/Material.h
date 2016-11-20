#pragma once

#include "Texture.h"

//TODO: Reflection and Refraction

class Material {
private:
    Texture* ambient;
    Texture* diffuse;
    Texture* specular;

    vec4 color;
public:
    Material::Material(Texture* t, vec4 c = vec4(1, 1, 1, 1));
    Material(Texture* a, Texture* d, Texture* s, vec4 c = vec4(1, 1, 1, 1));
    ~Material();

    Texture* getAmbient();
    Texture* getDiffuse();
    Texture* getSpecular();
    vec4 getBaseColor();

    void bind(Shader* shader, uint unit);
};