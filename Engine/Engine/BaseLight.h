#pragma once

class LightHandler;
class GameComponent;

class BaseLight abstract{
protected:
    vec3 color;
    bool colorChanged;
    float intensity;
    bool intensityChanged;

    GameComponent* component;

    BaseLight(vec3 c, float i, GameComponent* comp);
public:
    vec3 getColor();
    void setColor(vec3 c);

    float getIntensity();
    void setIntensity(float i);

    void forceUpdate();

    GameComponent* getComponent();
    mat4 getModelMatrix();
};