#pragma once

class Camera;

#include "InputManager.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Shader.h"
#include "RecourceLoader.h"
#include "Transform.h"
#include "Material.h"
#include "Camera.h"
#include <iostream>

class Game {
private:
    Transform* transform;
    Material* material;

    Mesh* floor;
    Mesh* mesh;

    DirectionalLight* directionalLight;
    PointLight* pointLight;
    SpotLight* spotLight;

    InputManager* input;
    Camera* camera;
    Shader* shader;
public:
    Game(InputManager* i);
    ~Game();

    void update(const double & delta);
    void render();
};

