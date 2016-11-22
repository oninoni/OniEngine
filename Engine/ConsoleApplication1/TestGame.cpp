#include "TestGame.h"

#include "Time.h"
#include "InputManager.h"

#include "Texture.h"
#include "Material.h"
#include "Mesh.h"

#include "MeshRenderer.h"
#include "GameObject.h"

#include "Shader.h"
#include "PhongShader.h"

TestGame::TestGame() : Game(){
}

TestGame::~TestGame(){
}

void TestGame::init() {
    Game::init();

    MeshRenderer* meshRenderer = new MeshRenderer(
        new Mesh(PhongShader::getInstance(), "Models/cube.obj"),
        new Material(new Texture("Textures/brick.png"), new Texture("Textures/brick.png"), new Texture("Textures/brick.png"))
    );

    GameObject* cubeObject = new GameObject();

    cubeObject->addComponent(meshRenderer);

    getRootGameObject()->addChild(cubeObject);
}