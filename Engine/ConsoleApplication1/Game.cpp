#include "stdafx.h"

#include "InputManager.h"
#include "GameObject.h"
#include "Shader.h"
#include "Camera.h"

#include "Game.h"

Game::Game() {
    camera = new Camera(800 / 600, 0.1, 1000, 70 * 3.141 / 360);
}

Game::~Game() {
    delete camera;
}

void Game::init() {
}

void Game::update(const double & delta, InputManager * input) {
    getRootGameObject()->update(delta, input);
}

GameObject* Game::getRootGameObject() {
    if (root == NULL)
        root = new GameObject();

    return root;
}

Camera * Game::getCamera() {
    return camera;
}
