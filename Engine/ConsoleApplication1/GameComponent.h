#pragma once

#include "stdafx.h"

class InputManager;
class Camera;
class Shader;

class GameComponent {
protected:
    GameComponent();
    ~GameComponent();
public:
    virtual void init(Transform* transform);
    virtual void update(Transform* transform, const double & delta, InputManager* input);
    virtual void render(Transform* transform, Shader* shader, Camera* camera);
};