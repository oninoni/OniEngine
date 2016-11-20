#include "Game.h"

Game::Game(InputManager* i) {
    input = i;

    shader = new Shader("basic");
    shader->addAttribute("v_position", GL_FLOAT, 3);
    shader->addAttribute("v_normal", GL_FLOAT, 3);
    shader->addAttribute("v_uv", GL_FLOAT, 2);

    camera = new Camera(800, 600, 0.1f, 1000, 70.0f);
    camera->getTransform()->position = vec3(0, 0, 5);

    mesh = new Mesh(shader, "Models/cube.obj");
    material = new Material(new Texture("Textures/brick.png"), vec4(1, 1, 1, 1));

    shader->setUniformVec3(shader->getUniformLocation("l_ambient"), vec3(0.1, 0.1, 0.1));

    transform = new Transform();
    //transform->rotation = vec3(-90, 0, 0);
    //transform->scale = vec3(0.1, 0.1, 0.1s
}

Game::~Game() {
    delete camera;
    delete shader;
}

void Game::update(const double & delta) {
    camera->updateFreeCam(delta, input);
}

void Game::render() {
    camera->render(shader, transform->getTransformationMatrix());

    shader->bind();
    material->bind(shader, 0);
    mesh->render();
}