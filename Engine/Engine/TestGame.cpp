#include "stdafx.h"

#include "InputManager.h"

#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "PhongShader.h"

#include "C_MeshRenderer.h"
#include "C_Camera.h"
#include "C_DirectionalLight.h"
#include "GameObject.h"

#include "TestGame.h"
#include "Time.h"

TestGame::TestGame(){
}

TestGame::~TestGame(){
}

void TestGame::init() {
    Game::init();

    Mesh* mesh = new Mesh(PhongShader::getInstance(), "Models/cube.obj");
    Material* material = new Material(new Texture("Textures/brick.png"), new Texture("Textures/brick.png"), new Texture("Textures/brick.png"));

    C_MeshRenderer* cube = new C_MeshRenderer(mesh, material);
    C_MeshRenderer* floor = new C_MeshRenderer(mesh, material);

    C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 0, 0), 1, vec3(1, -1, 1));

    c_camera = new C_Camera(getCamera());

    floorObject = new GameObject();
    cubeObject1 = new GameObject();
    cameraObject = new GameObject();

    cameraObject->getTransform().position = vec3(0, 1, 0);

    floorObject->addComponent(floor);
    floorObject->getTransform().offset = vec3(-.5f, -.5f, -.5f);
    floorObject->getTransform().scale = vec3(10, 1, 10);

    cubeObject1->addComponent(cube);
    cubeObject1->addComponent(dLight);
    cubeObject1->getTransform().scale = vec3(.1f, 1, .1f);
    cubeObject1->getTransform().position = vec3(0, 5, 0);

    cameraObject->addComponent(c_camera);

    getRootGameObject()->addChild(floorObject);
    floorObject->addChild(cubeObject1);
    getRootGameObject()->addChild(cameraObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);
    c_camera->updateFreeCam(delta, input);

    if (input->keyPressed(KeyAction::kaFirePrimary) && cubeObject1) {
        delete cubeObject1;
        cubeObject1 = NULL;
    }
}