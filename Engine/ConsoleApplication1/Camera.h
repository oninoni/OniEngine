#pragma once

class InputManager;
class Shader;

struct Perspective {
    float zNear;
    float zFar;
    float aspectRatio;
    float fov;
};

class Camera {
private:
    Transform* transform;
    mat4 projectionMatrix;

    Perspective perspective;
public:
    Camera(float aspectRatio, float zNear, float zFar, float fov);
    ~Camera();

    Transform* getTransform();

    void updateFreeCam(const double & delta, InputManager* input);

    void render(Shader* shader, const mat4 & modelmatrix);
};