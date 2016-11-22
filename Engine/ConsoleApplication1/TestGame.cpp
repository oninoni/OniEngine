#include "stdafx.h"

#include "InputManager.h"

#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "PhongShader.h"

#include "C_MeshRenderer.h"
#include "GameObject.h"

#include "Camera.h"
#include "TestGame.h"

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

    GameObject* cubeObject = new GameObject();

    cubeObject->addComponent(meshRenderer);

    getRootGameObject()->addChild(cubeObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    getCamera()->updateFreeCam(delta, input);
}