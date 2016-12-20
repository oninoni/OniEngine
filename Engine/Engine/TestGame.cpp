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

    Material* material = new Material(brickTexture, 0.02f, 1.0f);

    C_MeshRenderer* cube = new C_MeshRenderer(mesh, material);
    C_MeshRenderer* plane = new C_MeshRenderer(mesh2, material);

    C_PointLight* pLight = new C_PointLight(2, vec3(1, 0, 0));
    C_SpotLight* sLight = new C_SpotLight(vec3(0.8, 1.0, 0.5), 20, 45, true);

    c_camera = new C_Camera(getCamera());

    GameObject* planeObject = new GameObject();
    cubeObject = new GameObject();
    cameraObject = new GameObject();

    cubeObject->addComponent(cube);
    cubeObject->getTransform().offset = vec3(-.5, -.5, -.5);
    cubeObject->getTransform().position = vec3(0, .5, 0);

    planeObject->getTransform().rotation = vec3(-90, 0, 0);
    planeObject->getTransform().scale = 10;

    cameraObject->getTransform().position = vec3(0, 0.5, 3);

    for (int i = 0; i < 1; i++) {
        C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 1, 1), true);
        dLight->setIntensity(0.8);
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

    getRootGameObject()->addChild(cubeObject);
    getRootGameObject()->addChild(cameraObject);
    getRootGameObject()->addChild(planeObject);
}

void TestGame::update(const double & delta, InputManager * input) {
    Game::update(delta, input);
    c_camera->updateFreeCam(delta, input);

    spotLight->getTransform().position = vec3(sin((float) Time::getTime() * 0.1f) * 3.0f, .5f, cos((float) Time::getTime() * 0.1f) * 3.0f);
    spotLight->getTransform().rotation = vec3(0, (float) Time::getTime() * 18.0f / PI, 0);

    cubeObject->getTransform().rotation = vec3((float)Time::getTime() * 16.0f, 0, 0);
}