#include "Game.h"

Game::Game(InputManager* i) {
    input = i;

    shader = new Shader("basic");
    shader->addAttribute("v_position", GL_FLOAT, 3);
    shader->addAttribute("v_normal", GL_FLOAT, 3);
    shader->addAttribute("v_uv", GL_FLOAT, 2);

    camera = new Camera(800, 600, 0.1f, 1000, 70.0f);
    camera->getTransform()->position = vec3(0, 5, 5);

    mesh = new Mesh(shader, "Models/cube.obj");
    floor = new Mesh(shader, "Models/cube.obj");
    material = new Material(new Texture("Textures/brick.png"), new Texture("Textures/brick.png"), new Texture("Textures/brick.png"), 128.0f);

    shader->setUniformVec3("l_ambient", vec3(0.1, 0.1, 0.1));

    transform = new Transform();

    directionalLight = new DirectionalLight(vec3(1, 1, 1), 1, vec3(-0.4, -0.3, -0.2));
    shader->setUniformDLight("l_directionalLight", directionalLight);
    
    //pointLight = new PointLight(vec3(-2.5, 2, -2.1), 20, vec3(1, 1, 1), 1, 0, 0, 1);
    //shader->setUniformPLight("l_pointLights[0]", pointLight);

    spotLight = new SpotLight(vec3(0, -1, 0), .9, vec3(0, 1, 0), 20, vec3(1, 0, 0), 1, 0, 0, .5);
    shader->setUniformSLight("l_spotLights[0]", spotLight);

    //transform->rotation = vec3(-90, 0, 0);
    //transform->scale = vec3(0.1, 0.1, 0.1s
}

Game::~Game() {
    delete camera;
    delete shader;

    delete directionalLight;
}

double lastTime = 0;

void Game::update(const double & delta) {
    camera->updateFreeCam(delta, input);
}

void Game::render() {
    shader->bind();
    material->bind(shader, 0);

    spotLight->setDirection(vec3(sin(Time::getTime()), -1, 0));
    shader->setUniformSLight("l_spotLights[0]", spotLight);

    transform->position = vec3(0, 0, 0);
    transform->scale = vec3(1, 1, 1);
    transform->rotation = vec3(0, 0, 0);
    transform->offset = vec3(-.5, -.5, -.5);

    camera->render(shader, transform->getTransformationMatrix());
    mesh->render();

    transform->position = vec3(0, -.5, 0);
    transform->scale = vec3(50, 0.1, 50);
    transform->rotation = vec3(0, 0, 0);
    transform->offset = vec3(-.5, -.5, -.5);

    camera->render(shader, transform->getTransformationMatrix());
    floor->render();



}