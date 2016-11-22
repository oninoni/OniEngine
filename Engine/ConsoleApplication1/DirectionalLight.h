#pragma once

#include "stdafx.h"

#include "BaseLight.h"

class DirectionalLight : public BaseLight {
protected:
    vec3 direcion;
public:
    DirectionalLight(vec3 c, float i, vec3 d);
    ~DirectionalLight();

    vec3 getDirection();
    void setDirection(vec3 direction);
};