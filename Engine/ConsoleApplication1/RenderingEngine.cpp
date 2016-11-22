#include "RenderingEngine.h"

#include "PhongShader.h"
#include "GameObject.h"
#include "Camera.h"

RenderingEngine::RenderingEngine() {
    shader = PhongShader::getInstance();

    camera = new Camera(800, 700, 0.1f, 1000, 70);
    camera->getTransform()->position = vec3(0, 2, 0);
}

RenderingEngine::~RenderingEngine() {
}

void RenderingEngine::render(GameObject * object) {
    object->render(shader, camera);
}
