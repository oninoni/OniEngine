#pragma once

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

    Camera* camera;
    Mesh* mesh;
    Shader* shader;
public:
    Game();
    ~Game();

    void input();
    void update();
    void render();
};

