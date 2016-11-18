#include "Game.h"

Game::Game() {
    Vertex vertices[3] = {
        Vertex(vec3(-1, -1, 0)),
        Vertex(vec3(0, 1, 0)),
        Vertex(vec3(1, -1, 0)),
    };

    mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    shader = new Shader("basic");
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
