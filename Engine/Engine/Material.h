#pragma once

class Texture;
class Shader;

//TODO: Reflection and Refraction

class Material {
private:
    vec4 color;

    Texture* ambient;

    Texture* diffuse;

    Texture* specular;
    float specularReflectance;
    float specularExponent;

    Texture* normal;

    Texture* displacement;
    float displacementScale;
    float displacementBias;
public:
    //Material::Material(Texture* t, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    Material(Texture* ambient, Texture* diffuse, Texture* specular, Texture* normal, Texture* displacement, float dS = 0, float dB = 0, float sE = 8, float sR = 1, vec4 c = vec4(1, 1, 1, 1));
    ~Material();

    Texture* getAmbient();
    Texture* getDiffuse();
    Texture* getSpecular();
    Texture* getNormal();
    Texture* getDisplacement();
    vec4 getBaseColor();

    void bind(Shader* shader, uint unit);
};