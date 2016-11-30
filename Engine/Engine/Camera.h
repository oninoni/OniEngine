#pragma once

class InputManager;
class Shader;

class Camera {
protected:
    mat4 viewMatrix;

    mat4 projectionMatrix;
public:
    void setViewMatrix(mat4 matrix);

    void render(Shader* shader, const mat4 & modelmatrix);

    mat4 getViewProjectionMatrix();
};