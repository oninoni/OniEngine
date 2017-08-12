#pragma once

#include "GameProperty.h"

class CP_Physics : public GameProperty {
private:
    float mass;

    vec3 velocity;
    Quaternion angularVelocity;
public:
    CP_Physics(float mass, vec3 velocity = vec3(0, 0, 0), Quaternion angularVelocity = Quaternion());
    ~CP_Physics();

    void c_update(const double & delta, InputManager* input);
};