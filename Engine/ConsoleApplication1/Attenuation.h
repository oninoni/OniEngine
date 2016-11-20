#pragma once

class Attenuation {
protected:
    float constant;
    float linear;
    float square;

    Attenuation(float c, float l, float s);
public:
    float getConstant();
    void setConstant(float c);

    float getLinear();
    void setLinear(float l);

    float getSquare();
    void setSquare(float s);
};