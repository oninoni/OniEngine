#include "Game.h"

Game::Game() {

    Vertex vertices[] = {

        Vertex(vec3(-1, -1, 1), vec4(1, 0, 0, 1)),
        Vertex(vec3(0, 1, 0), vec4(0, 1, 0, 1)),
        Vertex(vec3(1, -1, 1), vec4(0, 0, 1, 1)),

        Vertex(vec3(1, -1, 1), vec4(0, 0, 1, 1)),
        Vertex(vec3(0, 1, 0), vec4(0, 1, 0, 1)),
        Vertex(vec3(1, -1, -1), vec4(1, 0, 0, 1)),

        Vertex(vec3(1, -1, -1), vec4(1, 0, 0, 1)),
        Vertex(vec3(0, 1, 0), vec4(0, 1, 0, 1)),
        Vertex(vec3(-1, -1, -1), vec4(0, 0, 1, 1)),

        Vertex(vec3(-1, -1, -1), vec4(0, 0, 1, 1)),
        Vertex(vec3(0, 1, 0), vec4(0, 1, 0, 1)),
        Vertex(vec3(-1, -1, 1), vec4(1, 0, 0, 1)),

        Vertex(vec3(-1, -1, 1), vec4(1, 0, 0, 1)),
        Vertex(vec3(1, -1, 1), vec4(0, 0, 1, 1)),
        Vertex(vec3(-1, -1, -1), vec4(0, 0, 1, 1)),

        Vertex(vec3(-1, -1, -1), vec4(0, 0, 1, 1)),
        Vertex(vec3(1, -1, 1), vec4(0, 0, 1, 1)),
        Vertex(vec3(1, -1, -1), vec4(1, 0, 0, 1)),
    };

    shader = new Shader("basic");
    
    shader->addAttribute("v_position", GL_FLOAT, 3);
    shader->addAttribute("v_color", GL_FLOAT, 4);

    camera = new Camera(800, 600, 0.1f, 1000, 70.0f, vec3(0, 0, 5));

    mesh = new Mesh(shader, vertices, 18);
    transform = new Transform();
}

Game::~Game() {
    delete mesh;
    delete shader;
    delete transform;
}

void Game::input() {
    InputManager* input = InputManager::getInstance();
}

void Game::update() {
    vec3 rot;
    rot.yaw = Time::getTime() * 90;
    
    vec3 rot2;
    rot2.yaw = sin(Time::getTime()) * 20;

    transform->rotation = rot;

    camera->getTransform()->rotation = rot2;
}

void Game::render() {
    camera->render(shader, transform->getTransformationMatrix());

    shader->bind();
    mesh->render();
}
