#include "stdafx.h"

#include "InputManager.h"

#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "PhongShader.h"

#include "C_MeshRenderer.h"
#include "C_Camera.h"
#include "GameObject.h"

#include "Camera.h"
#include "TestGame.h"
#include "Time.h"

TestGame::TestGame() : Game(){
}

TestGame::~TestGame(){
}

void TestGame::init() {
    Game::init();

    C_MeshRenderer* meshRenderer = new C_MeshRenderer(
        new Mesh(PhongShader::getInstance(), "Models/cube.obj"),
        new Material(new Texture("Textures/brick.png"), new Texture("Textures/brick.png"), new Texture("Textures/brick.png"))
    );

    C_Camera* c_camera = new C_Camera(getCamera());

    meshRenderer->getTransform().offset = vec3(-.5f, -.5f, -.5f);

    cubeObject1 = new GameObject();
    cameraObject = new GameObject();

    cameraObject->getTransform().offset = vec3(0, 0, 5);

    cubeObject1->addComponent(meshRenderer);
    cameraObject->addComponent(c_camera);

    getRootGameObject()->addChild(cubeObject1);
    cubeObject1->addChild(cameraObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);

    cameraObject->getTransform().rotation = vec3(0, Time::getTime() * 90, 0);
    cubeObject1->getTransform().rotation = vec3(0, Time::getTime() * 90, 0);
    cameraObject->getTransform().position = vec3(0, 0, Time::getTime());
    //getCamera()->updateFreeCam(delta, input);
}