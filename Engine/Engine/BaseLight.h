#pragma once

class LightHandler;
class GameComponent;

class BaseLight abstract{
protected:
    vec3 color;
    float intensity;
    bool colorChanged;
    int shadowMapID;
    bool shadowMapIDChanged;

    GameComponent* component;

    BaseLight(GameComponent* component, vec3 color);
public:
    vec3 getColor();
    void setColor(vec3 color);

    float getIntensity();
    void setIntensity(float intensity);

    vec3 getTrueColor();

    int getShadowMapID();
    void setShadowMapID(int shadowMapID);

    void forceUpdate();

    mat4 getTransformationMatrix(bool inverted);
};