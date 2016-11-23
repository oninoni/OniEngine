#pragma once

class Camera;
class Shader;
class InputManager;

#include "GameObject.h"

class GameComponent {
protected:
    GameComponent();
    ~GameComponent();

    GameObject* parent;

    mat4 getTransformationMatrix(bool inverted = false);
public:
    virtual void init(GameObject* parent);
    virtual void update(const double & delta, InputManager* input);
    virtual void render(Shader* shader, Camera* camera);

};