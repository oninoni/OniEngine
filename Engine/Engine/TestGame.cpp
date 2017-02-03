#include "stdafx.h"

#include "InputManager.h"

#include "TextureArray.h"
#include "Material.h"
#include "Mesh.h"

#include "CR_MeshRenderer.h"
#include "CR_Camera.h"
#include "CR_DirectionalLight.h"
#include "CR_PointLight.h"
#include "CR_SpotLight.h"
#include "GameObject.h"

#include "ShaderHandler.h"

#include "Time.h"
#include "RenderingEngine.h"

#include "TestGame.h"

TestGame::TestGame(){
}

TestGame::~TestGame(){
}

void TestGame::init(ShaderHandler* shaderHandler) {
    Game::init(shaderHandler);

    Mesh* mesh = new Mesh(shaderHandler, "Models/cube.obj");
    Mesh* mesh2 = new Mesh(shaderHandler, MeshType::Plane, 16);

    TextureArray* brickTexture = new TextureArray(4, GL_RGBA);
    brickTexture->loadImage(0, "Textures/bricks2.png");
    brickTexture->loadImage(1, "Textures/bricks2_spec.png");
    brickTexture->loadImage(2, "Textures/bricks2_normal.png");
    brickTexture->loadImage(3, "Textures/bricks2_disp.png");
    TextureArray* grassTexture = new TextureArray(4, GL_RGBA);
    grassTexture->loadImage(0, "Textures/grass01.png");
    grassTexture->loadImage(1, "Textures/grass01_spec.png");
    grassTexture->loadImage(2, "Textures/grass01_normal.png");
    grassTexture->loadImage(3, "Textures/grass01_disp.png");

    Material* brickMaterial = new Material(brickTexture, 0.02f, 1.0f);
    Material* grassMaterial = new Material(grassTexture, 0.02f, 1.0f);

    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            CR_MeshRenderer* cube = new CR_MeshRenderer(mesh, brickMaterial);
            GameObject* cubeObject = new GameObject();
            cubeObject->addComponent(cube);
            cubeObject->getTransform().offset = vec3(-0.5, -0.5, -0.5);
            cubeObject->getTransform().position = vec3(x * 2.0f, 0.5, y * 2.0f);

            getRootGameObject()->addChild(cubeObject);
        }
    }

    CR_MeshRenderer* plane = new CR_MeshRenderer(mesh2, grassMaterial);

    c_camera = new CR_Camera(getCamera());

    GameObject* planeObject = new GameObject();
    cameraObject = new GameObject();

    planeObject->getTransform().rotation = vec3(-90, 0, 0);
    planeObject->getTransform().scale = 10;

    cameraObject->getTransform().position = vec3(0, 0.5, 3);

    for (int i = 0; i < 1; i++) {
        CR_DirectionalLight* dLight = new CR_DirectionalLight(vec3(1, 1, 1), true);
        dLight->setIntensity(2.0f);
        GameObject* sun = new GameObject();
        //sun->addComponent(dLight);
        sun->getTransform().rotation = vec3(-1, 45 + (90.0f * i), 0);
        getRootGameObject()->addChild(sun);
    }

    sLight = new CR_SpotLight(vec3(1, 0.7f, 0.3f), 20, 45, true);
    spotLight = new GameObject();
    sLight->setIntensity(1.0f);
    spotLight->addComponent(sLight);
    spotLight->getTransform().position = vec3(0, .5, 8);
    getRootGameObject()->addChild(spotLight);
    
    cameraObject->addComponent(c_camera);
    planeObject->addComponent(plane);

    getRootGameObject()->addChild(cameraObject);
    getRootGameObject()->addChild(planeObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);
    c_camera->updateFreeCam(delta, input);

    spotLight->getTransform().position = vec3(sin((float) Time::getTime() * 0.1f) * 8.0f, 0.5f, cos((float) Time::getTime() * 0.1f) * 8.0f);
    spotLight->getTransform().rotation = vec3(0, (float) Time::getTime() * 18.0f / PI, 0);
}