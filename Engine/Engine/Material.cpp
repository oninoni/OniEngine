#include "stdafx.h"

#include "Texture.h"
#include "Shader.h"

#include "Material.h"

Material::Material(Texture* t, float sE, float sR, vec4 c): Material(t, t, t, sE, sR, c) {

}

Material::Material(Texture * a, Texture * d, Texture* s, float sE, float sR, vec4 c) {
    ambient = a;
    diffuse = d;
    specular = s;
    color = c;
    specularExponent = sE;
    specularReflectance = sR;
}

Material::~Material() {
}

Texture * Material::getAmbient() {
    return ambient;
}

Texture * Material::getDiffuse() {
    return diffuse;
}

Texture * Material::getSpecular() {
    return specular;
}

vec4 Material::getBaseColor() {
    return color;
}

void Material::bind(Shader* shader, uint unit) {
    ambient->bind(unit + 0);
    diffuse->bind(unit + 1);
    specular->bind(unit + 2);

    shader->setUniformVec4("f_color", color);

    shader->setUniformI("f_ambient", unit + 0);

    shader->setUniformI("f_diffuse", unit + 1);

    shader->setUniformI("f_specular", unit + 2);
    shader->setUniformF("f_specularExponent", specularExponent);
    shader->setUniformF("f_specularReflectance", specularReflectance);

}