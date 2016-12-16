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

#include "TextureArrayFramebuffer.h"
#include "LightHandler.h"
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
    Mesh* mesh2 = new Mesh(shaderHandler, MeshType::Plane);

    TextureArray* brickTexture = new TextureArray(4, 512, 512, GL_RGBA);
    brickTexture->loadImage(0, "Textures/bricks2.png");
    brickTexture->loadImage(1, "Textures/bricks2_spec.png");
    brickTexture->loadImage(2, "Textures/bricks2_normal.png");
    brickTexture->loadImage(3, "Textures/bricks2_disp.png");

    Material* material = new Material(brickTexture, 0.02f, 1.0f);
    Material* material2 = new Material(LightHandler::shadowMaps);

    C_MeshRenderer* cube = new C_MeshRenderer(mesh, material);
    C_MeshRenderer* plane = new C_MeshRenderer(mesh2, material);

    //C_DirectionalLight* dLight = new C_DirectionalLight(vec3(1, 1, 1), 1, vec3(-1, -1, -1));
    //C_PointLight* pLight = new C_PointLight(vec3(0, 5, 0), 10, vec3(1, 0, 0), 1);
    C_SpotLight* sLight = new C_SpotLight(vec3(0, 0, 0), 40, vec3(0, 0, 0), 20, vec3(1, 1, 1), 1);

    c_camera = new C_Camera(getCamera());

    GameObject* planeObject = new GameObject();
    cubeObject = new GameObject();
    cameraObject = new GameObject();

    cubeObject->getTransform().position = vec3(0, .5, 0);

    planeObject->getTransform().rotation = vec3(-90, 0, 0);
    //planeObject->getTransform().scale = vec3(4, 4, 4);

    cameraObject->getTransform().position = vec3(0, 0.5, 3);

    cubeObject->addComponent(cube);
    cubeObject->getTransform().offset = vec3(-.5f);
    
    //getRootGameObject()->addComponent(dLight);
    //getRootGameObject()->addComponent(pLight);

    spotLight = new GameObject();
    spotLight->addComponent(sLight);
    spotLight->getTransform().position = vec3(0, .5, 3);
    spotLight->getTransform().rotation = vec3(0, 0, 0);
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

    //spotLight->getTransform().position = vec3(sin(Time::getTime()) * 5.0f, 5, cos(Time::getTime()) * 5.0f);
    //spotLight->getTransform().rotation = vec3(Time::getTime() * 90.0f, 0, 0);

    //int err = glGetError();
    //if(err)
        //cerr << "Error: " << err << endl;
    /*if (input->keyPressed(KeyAction::kaFirePrimary) && cubeObject1) {
        delete cubeObject1;
        cubeObject1 = NULL;
    }*/
}