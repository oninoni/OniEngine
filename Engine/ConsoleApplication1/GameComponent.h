#pragma once

class Camera;
class Shader;
class InputManager;

#include "GameObject.h"

class GameComponent {
protected:
    GameComponent();
    string name;

    GameObject* parent;

    mat4 getTransformationMatrix(bool inverted = false);
public:
    virtual void init(GameObject* parent, string name);
    virtual void update(const double & delta, InputManager* input);
    virtual void render(Shader* shader, Camera* camera);

    virtual string GetDafaultName() = 0;

    string getName();
};