#pragma once

class Shader;

class Attenuation {
protected:
    float constant;
    float linear;
    float square;

    Attenuation(float range);
    Attenuation(float c, float l, float s);

    void setUniformAttenuation(Shader* shader, string uniformLocation);
};