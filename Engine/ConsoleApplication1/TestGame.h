#pragma once

#include "Game.h"

class GameObject;

class TestGame : public Game{
private:
    GameObject* cameraObject;
    GameObject* cubeObject1;
public:
    TestGame();
    ~TestGame();

    void init();
    void update(const double & delta, InputManager* input);
};

