#pragma once

#include "Game.h"

class GameObject;
class C_Camera;

class ShaderHandler;

class TestGame : public Game{
private:
    GameObject* cameraObject;
    GameObject* spotLight;
    C_Camera* c_camera;
public:
    TestGame();
    ~TestGame();

    void init(ShaderHandler* shaderHandler);
    void update(const double & delta, InputManager* input);
};