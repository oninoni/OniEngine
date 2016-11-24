#include "stdafx.h"

#include "C_Camera.h"
#include "Camera.h"
#include "InputManager.h"

#define FLYSPEED 4
#define TURNSPEED 20

C_Camera::C_Camera(Camera* camera) {
    this->camera = camera;
}

string C_Camera::GetDafaultName() {
    return "C_Camera";
}

void C_Camera::updateFreeCam(const double & delta, InputManager * input) {
    vec3 cameraMovement;
    if (input->keyDown(KeyAction::kaSpace)) {
    cameraMovement += parent->getTransform().getUp()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaShift)) {
    cameraMovement += parent->getTransform().getUp()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaLeft)) {
    cameraMovement += parent->getTransform().getLeft()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaRight)) {
    cameraMovement += parent->getTransform().getLeft()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaForward)) {
    cameraMovement += parent->getTransform().getForward()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaBack)) {
    cameraMovement += parent->getTransform().getForward()* -(float)(delta * FLYSPEED);
    }
    parent->getTransform().position += cameraMovement;

    vec3 cameraRotation;
    vec2 mousePos = input->getMousePos();

    cameraRotation.yaw = -mousePos.x * TURNSPEED;
    cameraRotation.pitch = max(min(mousePos.y * TURNSPEED, 90.0f), -90.0f);

    parent->getTransform().rotation = cameraRotation;
}

void C_Camera::update(const double & delta, InputManager * input) {
    mat4 viewMatrix = getTransformationMatrix(true);
    camera->setViewMatrix(viewMatrix);
}