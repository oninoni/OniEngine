#pragma once

class Camera;
class Shader;
class InputManager;

#include "GameObject.h"

class GameComponent abstract {
protected:
    GameComponent();

    GameObject* parent;
public:
    ~GameComponent();

    void init(GameObject* parent);
    void update(const double & delta, InputManager* input);
    void preRender(Shader* shader);
    void render(Shader* shader, Camera* camera);

    virtual void c_init(GameObject* parent) {}
    virtual void c_update(const double & delta, InputManager* input) {}
    virtual void c_preRender(Shader* shader) {}
    virtual void c_render(Shader* shader, Camera* camera) {}
    virtual void c_destroy() {}

    void setParent(GameObject* parent);
    mat4 getTransformationMatrix(bool inverted = false);
};