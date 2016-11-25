#include "stdafx.h"

#include "Shader.h"
#include "InputManager.h"

#include "Camera.h"

#define FLYSPEED 4
#define TURNSPEED 20

void Camera::setViewMatrix(mat4 matrix) {
    this->viewMatrix = matrix;
}

void Camera::render(Shader* shader, const mat4 & modelmatrix) {
    shader->setUniformMat4("model", modelmatrix);
    shader->setUniformMat4("view", viewMatrix);

    shader->setUniformMat4("modelView", viewMatrix * modelmatrix);

    shader->setUniformMat4("modelViewProjection", projectionMatrix * viewMatrix * modelmatrix);
}
