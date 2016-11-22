#include "Game.h"

#include "InputManager.h"
#include "GameObject.h"
#include "Shader.h"
#include "Camera.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init() {

}

void Game::update(const double & delta, InputManager * input) {
    getRootGameObject()->update(delta, input);

    //camera->updateFreeCam(delta, input);
}

GameObject* Game::getRootGameObject() {
    if (root == NULL)
        root = new GameObject();

    return root;
}
