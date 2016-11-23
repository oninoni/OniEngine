#include "stdafx.h"

#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(float left, float right, float bottom, float top, float nearZ, float farZ) {
    setProjectionMatrix(left, right, bottom, top, nearZ, farZ));
}

void OrthogonalCamera::setProjectionMatrix(float left, float right, float bottom, float top, float nearZ, float farZ) {
    projectionMatrix.identity();

    float width = right - left;
    float height = top - bottom;
    float depth = farZ - nearZ;

    projectionMatrix[0][0] = 2 / width;
    projectionMatrix[1][1] = 2 / height;
    projectionMatrix[2][2] = -2 / depth;

    projectionMatrix[3][0] = -(right + left) / width;
    projectionMatrix[3][1] = -(top + bottom) / height;
    projectionMatrix[3][2] = -(farZ + nearZ) / depth;
}
