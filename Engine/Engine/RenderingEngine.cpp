#include "stdafx.h"

#include "PhongShader.h"
#include "GameObject.h"
#include "Camera.h"

#include "LightHandler.h"
#include "Window.h"

#include "TextureArrayFramebuffer.h"

#include "RenderingEngine.h"

TextureArrayFramebuffer* RenderingEngine::tempTarget;

RenderingEngine::RenderingEngine(Camera* camera, Window* window) {
    initGraphics();
    cout << getOpenGLVersion() << endl;

    shader = PhongShader::getInstance();
    tempTarget = new TextureArrayFramebuffer(1, 512, 512, GL_DEPTH_COMPONENT, GL_DEPTH_ATTACHMENT);

    this->camera = camera;
    this->window = window;
}

RenderingEngine::~RenderingEngine() {
}

void RenderingEngine::render(GameObject * root) {
    tempTarget->bindFramebuffer(0);
    clearScreen();

    root->preRender(shader);
    root->render(shader, camera);

    window->bindAsRenderTarget();
    clearScreen();

    root->preRender(shader);
    root->render(shader, camera);
}

void RenderingEngine::clearScreen() {
    //TODO Stencil Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingEngine::initGraphics() {
    glClearColor(0, 0, 0, 0);

    // Clockwise is front
    glFrontFace(GL_CCW);

    //Culling Back
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);

    //Enable z component on render result
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_DEPTH_CLAMP);
}

const char* RenderingEngine::getOpenGLVersion() {
    return (char*)glGetString(GL_VERSION);
}

void RenderingEngine::setClearColor(vec4 color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

inline void RenderingEngine::setClearColor(vec3 color) {
    glClearColor(color.r, color.g, color.b, 1.0);
}