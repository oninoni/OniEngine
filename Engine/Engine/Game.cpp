#include "stdafx.h"

#include "InputManager.h"
#include "GameObject.h"
#include "Shader.h"
#include "PerspectiveCamera.h"
#include "OrthogonalCamera.h"

#include "ShaderHandler.h"

#include "Game.h"

Game::Game() {
    camera = new PerspectiveCamera(1.0f, 0.1f, 1000.0f, 60.0f);
}

Game::~Game() {
    delete camera;
}

void Game::init(ShaderHandler* shaderHandler) {
}

void Game::update(const double & delta, InputManager * input) {
    getRootGameObject()->update(delta, input);
}

GameObject* Game::getRootGameObject() {
    if (!root)
        root = new GameObject();

    return root;
}

Camera * Game::getCamera() {
    return camera;
}
