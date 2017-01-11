#include "stdafx.h"

#include "Camera.h"
#include "InputManager.h"
#include "GameObject.h"
#include "ShaderHandler.h"

#include "CR_Camera.h"

#define FLYSPEED 4
#define TURNSPEED 20

CR_Camera::CR_Camera(Camera* camera) {
    this->camera = camera;
}

string CR_Camera::GetDafaultName() {
    return "C_Camera";
}

void CR_Camera::updateFreeCam(const double & delta, InputManager * input) {
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

void CR_Camera::c_update(const double & delta, InputManager * input) {
    mat4 viewMatrix = getTransformationMatrix(true);
    camera->setViewMatrix(viewMatrix);
}

void CR_Camera::c_preRender(ShaderHandler * shaderHandler, LightHandler * lightHandler, bool shadowRender) {
    if (shadowRender) {
        camera->bindViewMatrix((Shader*) shaderHandler->getShadowmapShader());
    } else {
        camera->bindViewMatrix((Shader*) shaderHandler->getPhongShader());
    }
}
