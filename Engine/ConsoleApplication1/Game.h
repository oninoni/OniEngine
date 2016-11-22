#pragma once

#include "stdafx.h"

class InputManager;
class GameObject;
class Camera;

class Game {
protected:
    GameObject* root;
public:
    Game();
    virtual ~Game() = 0;

    virtual void init();
    virtual void update(const double & delta, InputManager* input);

    GameObject* getRootGameObject();
};

