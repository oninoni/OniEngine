#include "stdafx.h"

#include "InputManager.h"

#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "PhongShader.h"

#include "C_MeshRenderer.h"
#include "C_Camera.h"
#include "C_DirectionalLight.h"
#include "C_PointLight.h"
#include "C_SpotLight.h"
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
    Texture* texture = new Texture("Textures/brick.png");
    Texture* textureS = new Texture("Textures/brickSpecular.png");
    Texture* textureN = new Texture("Textures/brickNormal.png");
    Material* material = new Material(texture, texture, textureS, textureN, texture);

    C_MeshRenderer* cube = new C_MeshRenderer(mesh, material);

    C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 1, 1), 1, vec3(1, -1, 1));
    //C_PointLight* pLight = new C_PointLight(vec3(0, 2, 0), 10, vec3(1, 0, 1), 1);
    //C_SpotLight* cLight = new C_SpotLight(vec3(0, -1, 0), 45, vec3(0, 5, 0), 10, vec3(0, 1, 1), 1);

    c_camera = new C_Camera(getCamera());

    cubeObject1 = new GameObject();
    cameraObject = new GameObject();

    cameraObject->getTransform().position = vec3(0, 0, 5);

    cubeObject1->addComponent(cube);
    cubeObject1->getTransform().offset = vec3(-.5f);
    getRootGameObject()->addComponent(dLight);
    //getRootGameObject()->addComponent(pLight);
    //getRootGameObject()->addComponent(cLight);

    cameraObject->addComponent(c_camera);

    getRootGameObject()->addChild(cubeObject1);
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