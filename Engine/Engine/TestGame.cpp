#include "stdafx.h"

#include "InputManager.h"

#include "Texture.h"
#include "TextureRenderTarget.h"
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

#include "RenderingEngine.h"

TestGame::TestGame(){
}

TestGame::~TestGame(){
}

void TestGame::init() {
    Game::init();

    Mesh* mesh = new Mesh(PhongShader::getInstance(), "Models/cube.obj");
    Texture* texture = new Texture("Textures/bricks2.png");
    Texture* textureS = new Texture("Textures/bricks2_spec.png");
    Texture* textureN = new Texture("Textures/bricks2_normal.png");
    Texture* textureD = new Texture("Textures/bricks2_disp.png");
    Material* material = new Material(texture, texture, textureS, textureN, textureD, 0.02f, 1.0f);

    C_MeshRenderer* cube = new C_MeshRenderer(mesh, material);

    C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 1, 1), 1, vec3(-1, -1, -1));
    C_PointLight* pLight = new C_PointLight(vec3(0, 0, -5), 10, vec3(1, 0, 0), 1);
    C_SpotLight* cLight = new C_SpotLight(vec3(0, -1, 0), 45, vec3(0, 5, 0), 10, vec3(0, 1, 1), 1);

    c_camera = new C_Camera(getCamera());

    cubeObject1 = new GameObject();
    cameraObject = new GameObject();

    cubeObject1->getTransform().scale = vec3(10, .1, 10);
    cameraObject->getTransform().position = vec3(0, 5, 5);

    cubeObject1->addComponent(cube);
    cubeObject1->getTransform().offset = vec3(-.5f);
    getRootGameObject()->addComponent(dLight);
    //getRootGameObject()->addComponent(pLight);
    //getRootGameObject()->addComponent(cLight);

    cameraObject->addComponent(c_camera);

    getRootGameObject()->addChild(cubeObject1);
    getRootGameObject()->addChild(cameraObject);

    Material* mat2 = new Material(RenderingEngine::tempTarget, RenderingEngine::tempTarget, RenderingEngine::tempTarget, RenderingEngine::tempTarget, RenderingEngine::tempTarget);
    C_MeshRenderer* screen = new C_MeshRenderer(mesh, mat2);
    GameObject* screenObject = new GameObject();
    screenObject->addComponent(screen);

    screenObject->getTransform().position = vec3(0, 4, 0);

    getRootGameObject()->addChild(screenObject); 
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);
    c_camera->updateFreeCam(delta, input);

    /*if (input->keyPressed(KeyAction::kaFirePrimary) && cubeObject1) {
        delete cubeObject1;
        cubeObject1 = NULL;
    }*/
}