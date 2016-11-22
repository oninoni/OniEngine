#include "stdafx.h"

#include "Shader.h"
#include "InputManager.h"

#include "Camera.h"

#define FLYSPEED 4
#define TURNSPEED 20

Camera::Camera(float aspectRatio, float zNear, float zFar, float fov) {
    setProjectionMatrix(aspectRatio, zNear, zFar, fov);
}

Camera::~Camera() {
}

void Camera::setViewMatrix(mat4 matrix) {
    this->viewMatrix = matrix;
}

void Camera::setProjectionMatrix(float aspectRatio, float zNear, float zFar, float fov) {
    projectionMatrix.SetProjectionMatrix(aspectRatio, zNear, zFar, fov);
}

/*
void Camera::updateFreeCam(const double & delta, InputManager* input) {
    vec3 cameraMovement;
    if (input->keyDown(KeyAction::kaSpace)) {
        cameraMovement += getTransform()->getUp()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaShift)) {
        cameraMovement += getTransform()->getUp()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaLeft)) {
        cameraMovement += getTransform()->getLeft()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaRight)) {
        cameraMovement += getTransform()->getLeft()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaForward)) {
        cameraMovement += getTransform()->getForward()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaBack)) {
        cameraMovement += getTransform()->getForward()* -(float)(delta * FLYSPEED);
    }
    getTransform()->position += cameraMovement;

    vec3 cameraRotation;
    vec2 mousePos = input->getMousePos();

    cameraRotation.yaw = -mousePos.x * TURNSPEED;
    cameraRotation.pitch = max(min(mousePos.y * TURNSPEED, 90.0f), -90.0f);

    getTransform()->rotation = cameraRotation;
}
*/
void Camera::render(Shader* shader, const mat4 & modelmatrix) {
    mat4 mvp = projectionMatrix * viewMatrix * modelmatrix;

    shader->setUniformMat4("model", modelmatrix);
    shader->setUniformMat4("view", viewMatrix);
    shader->setUniformMat4("projection", projectionMatrix);

    shader->setUniformMat4("modelViewProjection", mvp);
}
