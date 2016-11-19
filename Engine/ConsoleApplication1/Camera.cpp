#include "Camera.h"

Camera::Camera(int width, int height, float zNear, float zFar, float fov) {
    perspective.zNear = zNear;
    perspective.zFar = zFar;
    perspective.width = width;
    perspective.height = height;
    perspective.fov = fov;

    projectionMatrix.SetProjectionMatrix(width, height, zNear, zFar, fov);

    transform = new Transform(true);
}

Camera::~Camera() {
}

Transform * Camera::getTransform() {
    return transform;
}

void Camera::render(Shader* shader, const mat4 & modelmatrix) {
    mat4 mvp = projectionMatrix * transform->getTransformationMatrix() * modelmatrix;

    shader->setUniformMat4(shader->getUniformLocation("mvp"), mvp);
}
