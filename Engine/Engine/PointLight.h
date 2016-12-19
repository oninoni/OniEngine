#pragma once

#include "BaseLight.h"
#include "Attenuation.h"

class LightHandler;

class PointLight : public BaseLight, public Attenuation{
protected:
    vec3 position;
    bool positionChanged;
    float range;
    bool rangeChanged;
public:
    PointLight(GameComponent* component, vec3 position, float radius, vec3 color);
    PointLight(GameComponent* component, vec3 position, float radius, vec3 color, float constant, float linear, float square);

    void setUniformPointLight(LightHandler * lightHandler);

    vec3 getPosition();
    void setPosition(vec3 position);

    float getRange();
    void setRange(float radius);

    void forceUpdate();
};