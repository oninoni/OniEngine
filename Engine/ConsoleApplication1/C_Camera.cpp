#include "stdafx.h"

#include "C_Camera.h"
#include "Camera.h"

C_Camera::C_Camera(Camera* camera) {
    this->camera = camera;
}

C_Camera::~C_Camera() {
}

void C_Camera::update(GameObject * parent, const double & delta, InputManager * input) {
    mat4 viewMatrix = getTransformationMatrix(parent, true);

    camera->setViewMatrix(viewMatrix);
}