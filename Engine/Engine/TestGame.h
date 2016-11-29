#pragma once

#include "Game.h"

class GameObject;
class C_Camera;

class TestGame : public Game{
private:
    GameObject* cubeObject;
    GameObject* cameraObject;
    C_Camera* c_camera;
public:
    TestGame();
    ~TestGame();

    void init();
    void update(const double & delta, InputManager* input);
};