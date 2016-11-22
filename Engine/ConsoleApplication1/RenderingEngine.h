#pragma once

#include "stdafx.h"

class GameObject;
class Shader;
class Camera;

class RenderingEngine {
private:
    Shader* shader;
    Camera* camera;
public:
    RenderingEngine();
    ~RenderingEngine();

    void render(GameObject* object);
};

