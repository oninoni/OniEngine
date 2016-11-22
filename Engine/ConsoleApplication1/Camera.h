#pragma once

class InputManager;
class Shader;

class Camera {
private:
    mat4 viewMatrix;

    mat4 projectionMatrix;
public:
    Camera(float aspectRatio, float zNear, float zFar, float fov);
    ~Camera();

    void setViewMatrix(mat4 matrix);
    void setProjectionMatrix(float aspectRatio, float zNear, float zFar, float fov);

    void render(Shader* shader, const mat4 & modelmatrix);
};