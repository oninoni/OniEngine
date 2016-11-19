#pragma once

class Camera;

#include "InputManager.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Shader.h"
#include "RecourceLoader.h"
#include "Transform.h"
#include "Camera.h"
#include <iostream>

class Game {
private:
    Transform* transform;
    InputManager* input;
    
    Camera* camera;
    Mesh* mesh;
    Shader* shader;
public:
    Game(InputManager* i);
    ~Game();

    void update(const double & delta);
    void render();
};

