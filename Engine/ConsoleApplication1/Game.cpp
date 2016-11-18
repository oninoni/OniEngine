#include "Game.h"

Game::Game() {
    mesh = new Mesh();
    shader = new Shader();

    int lengthV = 0;
    char* dataV = RecourceLoader::loadShader("basicVertex.vs", lengthV);
    shader->addVertexShader(dataV, lengthV);
    int lengthF = 0;
    char* dataF = RecourceLoader::loadShader("basicFragment.fs", lengthF);
    cout << dataF << endl;
    shader->addFragmentShader(dataF, lengthF);

    shader->compileShader();
}


Game::~Game() {
}

void Game::input() {
    InputManager* input = InputManager::getInstance();
}

void Game::update() {
}

void Game::render() {
    shader->bind();
    mesh->render();
}
