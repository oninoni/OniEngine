#pragma once

struct Perspective {
    float zNear;
    float zFar;
    int width;
    int height;
    float fov;
};

class Camera {
private:
    Transform* transform;
    mat4 projectionMatrix;

    Perspective perspective;
public:
    Camera(int width, int height, float zNear, float zFar, float fov);
    ~Camera();

    Transform* getTransform();

    void updateFreeCam(const double & delta, InputManager* input);

    void render(Shader* shader, const mat4 & modelmatrix);
};