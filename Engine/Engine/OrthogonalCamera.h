#pragma once

#include "Camera.h"

class OrthogonalCamera : Camera{
public:
    OrthogonalCamera(float left, float right, float bottom, float top, float nearZ, float farZ);

    void setProjectionMatrix(float left, float right, float bottom, float top, float nearZ, float farZ);
};