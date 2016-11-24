#include "stdafx.h"

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float aspectRatio, float zNear, float zFar, float fov) {
    setProjectionMatrix(aspectRatio, zNear, zFar, fov);
}

void PerspectiveCamera::setProjectionMatrix(float aspectRatio, float zNear, float zFar, float fov) {
    projectionMatrix.SetProjectionMatrix(aspectRatio, zNear, zFar, fov);
}