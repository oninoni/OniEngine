#pragma once

#include "Camera.h"

class PerspectiveCamera :
    public Camera {
public:
    PerspectiveCamera(float aspectRatio, float zNear, float zFar, float fov);

    void setProjectionMatrix(float aspectRatio, float zNear, float zFar, float fov);
};