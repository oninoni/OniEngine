#pragma once

class Shader;

class Attenuation {
protected:
    float constant;
    bool constantChanged;
    float linear;
    bool linearChanged;
    float square;
    bool squareChanged;

    Attenuation(float range);
    Attenuation(float constant, float linear, float square);

    void forceUpdate();
public:
    float getConstant();
    void setConstant(float constant);

    float getLinear();
    void setLinear(float linear);

    float getSquare();
    void setSquare(float square);
};