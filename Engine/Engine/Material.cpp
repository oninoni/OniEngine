#include "stdafx.h"

#include "TextureArray.h"
#include "Shader.h"

#include "Material.h"

//Material::Material(Texture* t, float sE, float sR, vec4 c): Material(t, t, t, sE, sR, c) {
//}

Material::Material(TextureArray* textures, float displacementScale, float displacementOffset, float specularExponent, float specularReflectance, vec4 color) {
    this->textures = textures;
    this->displacementScale = displacementScale;
    this->displacementBias = ((displacementScale / 2) * displacementOffset) - (displacementScale / 2);
    this->specularExponent = specularExponent;
    this->specularReflectance = specularReflectance;
    this->color = color;
}

vec4 Material::getBaseColor() {
    return color;
}

void Material::setBaseColor(vec4 color) {
    this->color = color;
}

void Material::bind(Shader* shader, uint unit) {
    textures->bind(unit);

    shader->setUniformVec4("f_color", color);
    shader->setUniformI("f_materialTexture", unit);

    shader->setUniformF("f_specularExponent", specularExponent);
    shader->setUniformF("f_specularReflectance", specularReflectance);
    shader->setUniformF("f_dispMapScale", displacementScale);
    shader->setUniformF("f_dispMapBias", displacementBias);
}