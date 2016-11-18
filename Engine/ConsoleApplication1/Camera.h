#pragma once

#include "Transform.h"
#include "Shader.h"

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
    Camera(int width, int height, float zNear, float zFar, float fov, vec3 position = vec3());
    ~Camera();

    Transform* getTransform();

    void render(Shader* shader, const mat4 & modelmatrix);
};