#pragma once

class Texture;
class Shader;

//TODO: Reflection and Refraction

class Material {
private:
    Texture* ambient;
    Texture* diffuse;
    Texture* specular;
    Texture* normal;
    Texture* displacement;

    float specularReflectance;
    float specularExponent;

    vec4 color;
public:
    //Material::Material(Texture* t, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    Material(Texture* ambient, Texture* diffuse, Texture* specular, Texture* normal, Texture* displacement, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    ~Material();

    Texture* getAmbient();
    Texture* getDiffuse();
    Texture* getSpecular();
    Texture* getNormal();
    Texture* getDisplacement();
    vec4 getBaseColor();

    void bind(Shader* shader, uint unit);
};