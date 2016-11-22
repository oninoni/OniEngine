#include "stdafx.h"

#include "C_Camera.h"
#include "Camera.h"

C_Camera::C_Camera(Camera* camera) {
    this->camera = camera;
}

C_Camera::~C_Camera() {
}
