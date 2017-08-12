#include "stdafx.h"

#include "CP_Physics.h"

CP_Physics::CP_Physics(float mass, vec3 velocity, Quaternion angularVelocity) {
    this->mass = mass;
    this->velocity = velocity;
    this->angularVelocity = angularVelocity;
}

CP_Physics::~CP_Physics() {
}

void CP_Physics::c_update(const double & delta, InputManager * input) {
       
}
