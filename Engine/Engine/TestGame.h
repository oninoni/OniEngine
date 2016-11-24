#pragma once

#include "Game.h"

class GameObject;
class C_Camera;

class TestGame : public Game{
private:
    GameObject* floorObject;
    GameObject* cameraObject;
    GameObject* cubeObject1; 
    C_Camera* c_camera;
public:
    TestGame();
    ~TestGame();

    void init();
    void update(const double & delta, InputManager* input);
};

