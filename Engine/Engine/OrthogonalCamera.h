#pragma once

#include "Camera.h"

class OrthogonalCamera : public Camera{
public:
    OrthogonalCamera(float left, float right, float bottom, float top, float nearZ, float farZ);

    void setProjectionMatrix(float left, float right, float bottom, float top, float nearZ, float farZ);
};