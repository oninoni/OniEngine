#include "stdafx.h"

#include "InputManager.h"

#include "TextureArray.h"
#include "Material.h"
#include "Mesh.h"

#include "C_MeshRenderer.h"
#include "C_Camera.h"
#include "C_DirectionalLight.h"
#include "C_PointLight.h"
#include "C_SpotLight.h"
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
    Mesh* mesh2 = new Mesh(shaderHandler, MeshType::Plane, 5);

    TextureArray* brickTexture = new TextureArray(4, 512, 512, GL_RGBA);
    brickTexture->loadImage(0, "Textures/bricks2.png");
    brickTexture->loadImage(1, "Textures/bricks2_spec.png");
    brickTexture->loadImage(2, "Textures/bricks2_normal.png");
    brickTexture->loadImage(3, "Textures/bricks2_disp.png");
    TextureArray* grassTexture = new TextureArray(4, 1024, 1024, GL_RGBA);
    grassTexture->loadImage(0, "Textures/grass01.png");
    grassTexture->loadImage(1, "Textures/grass01_spec.png");
    grassTexture->loadImage(2, "Textures/grass01_normal.png");
    grassTexture->loadImage(3, "Textures/grass01_disp.png");

    Material* brickMaterial = new Material(brickTexture, 0.02f, 1.0f);
    Material* grassMaterial = new Material(grassTexture, 0.02f, 1.0f);

    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            C_MeshRenderer* cube = new C_MeshRenderer(mesh, brickMaterial);
            GameObject* cubeObject = new GameObject();
            cubeObject->addComponent(cube);
            cubeObject->getTransform().offset = vec3(-.5, -.5, -.5);
            cubeObject->getTransform().position = vec3(x * 2, .5, y * 2);

            getRootGameObject()->addChild(cubeObject);
        }
    }
    for (int i = 0; i < 4; i++) {
    }

    C_MeshRenderer* plane = new C_MeshRenderer(mesh2, grassMaterial);

    C_PointLight* pLight = new C_PointLight(vec3(0, 1, 1), 5);
    C_SpotLight* sLight = new C_SpotLight(vec3(1, 0.7f, 0.3f), 20, 45, true);

    c_camera = new C_Camera(getCamera());

    GameObject* planeObject = new GameObject();
    cameraObject = new GameObject();

    planeObject->getTransform().rotation = vec3(-90, 0, 0);
    planeObject->getTransform().scale = 10;

    cameraObject->getTransform().position = vec3(0, 0.5, 3);

    for (int i = 0; i < 1; i++) {
        C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 1, 1), true);
        dLight->setIntensity(0.8f);
        GameObject* sun = new GameObject();
        sun->addComponent(dLight);
        sun->getTransform().rotation = vec3(-45, 45 + (90.0f * i), 0);
        getRootGameObject()->addChild(sun);
    }

    GameObject* pointLightObject = new GameObject();
    //pointLightObject->addComponent(pLight);
    pointLightObject->getTransform().position = vec3(0, 1.5, 0);
    getRootGameObject()->addChild(pointLightObject);

    spotLight = new GameObject();
    sLight->setIntensity(4.0f);
    spotLight->addComponent(sLight);
    spotLight->getTransform().position = vec3(0, .5, 3);
    getRootGameObject()->addChild(spotLight);

    cameraObject->addComponent(c_camera);
    planeObject->addComponent(plane);

    getRootGameObject()->addChild(cameraObject);
    getRootGameObject()->addChild(planeObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);
    c_camera->updateFreeCam(delta, input);

    spotLight->getTransform().position = vec3(sin((float) Time::getTime() * 0.1f) * 8.0f, 2.0f, cos((float) Time::getTime() * 0.1f) * 8.0f);
    spotLight->getTransform().rotation = vec3(-45.0f, (float) Time::getTime() * 18.0f / PI, 0);
}