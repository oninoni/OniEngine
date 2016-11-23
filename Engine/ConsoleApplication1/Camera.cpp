#include "stdafx.h"

#include "Shader.h"
#include "InputManager.h"

#include "Camera.h"

#define FLYSPEED 4
#define TURNSPEED 20

void Camera::setViewMatrix(mat4 matrix) {
    this->viewMatrix = matrix;
}

void Camera::setProjectionMatrix(float aspectRatio, float zNear, float zFar, float fov) {
    projectionMatrix.SetProjectionMatrix(aspectRatio, zNear, zFar, fov);
}

void Camera::render(Shader* shader, const mat4 & modelmatrix) {
    mat4 mvp = projectionMatrix * viewMatrix * modelmatrix;

    shader->setUniformMat4("model", modelmatrix);
    shader->setUniformMat4("view", viewMatrix);
    shader->setUniformMat4("projection", projectionMatrix);

    shader->setUniformMat4("modelViewProjection", mvp);
}
