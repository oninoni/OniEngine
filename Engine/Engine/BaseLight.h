#pragma once

class LightHandler;
class GameProperty;

class BaseLight abstract{
protected:
    vec3 color;
    float intensity;
    bool colorChanged;

    int shadowMapID;
    bool shadowMapIDChanged;

    GameProperty* property;

    BaseLight(GameProperty* property, vec3 color);
public:
    vec3 getColor();
    void setColor(vec3 color);

    float getIntensity();
    void setIntensity(float intensity);

    int getShadowMapID();
    void setShadowMapID(int shadowMapID);

    void forceUpdate();

    mat4 getTransformationMatrix(bool inverted);
};