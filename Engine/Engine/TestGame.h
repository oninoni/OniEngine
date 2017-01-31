#pragma once

#include "Game.h"

class GameObject;
class CR_Camera;
class CR_SpotLight;

class ShaderHandler;

class TestGame : public Game{
private:
    GameObject* cameraObject;
    GameObject* spotLight;
    CR_Camera* c_camera;
    CR_SpotLight* sLight;
public:
    TestGame();
    ~TestGame();

    void init(ShaderHandler* shaderHandler);
    void update(const double & delta, InputManager* input);
};