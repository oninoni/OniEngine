#include "Game.h"

Game::Game(InputManager* i) {

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

    input = i;

    shader = new Shader("basic");
    
    shader->addAttribute("v_position", GL_FLOAT, 3);
    shader->addAttribute("v_color", GL_FLOAT, 4);

    camera = new Camera(800, 600, 0.1f, 1000, 70.0f);
    camera->getTransform()->position = vec3(0, 0, 5);

    mesh =// new Mesh(shader, vertices, 18);

    RecourceLoader::loadMesh("Models/alfa147.obj", shader);

    transform = new Transform();
}

Game::~Game() {
    delete mesh;
    delete shader;
    delete transform;
}

#define FLYSPEED 4
#define TURNSPEED 20

void Game::update(const double & delta) {
    vec3 cameraMovement;
    if (input->keyDown(KeyAction::kaSpace)) {
        cameraMovement += camera->getTransform()->getUp()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaShift)) {
        cameraMovement += camera->getTransform()->getUp()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaLeft)) {
        cameraMovement += camera->getTransform()->getLeft()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaRight)) {
        cameraMovement += camera->getTransform()->getLeft()* -(float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaForward)) {
        cameraMovement += camera->getTransform()->getForward()* (float)(delta * FLYSPEED);
    }
    if (input->keyDown(KeyAction::kaBack)) {
        cameraMovement += camera->getTransform()->getForward()* -(float)(delta * FLYSPEED);
    }
    camera->getTransform()->position += cameraMovement;

    vec3 cameraRotation;
    vec2 mousePos = input->getMousePos();

    cameraRotation.yaw = -mousePos.x * TURNSPEED;
    cameraRotation.pitch = max(min(mousePos.y * TURNSPEED, 90.0), -90.0);

    camera->getTransform()->rotation = cameraRotation;
}

void Game::render() {
    camera->render(shader, transform->getTransformationMatrix());

    shader->bind();
    mesh->render();
}
