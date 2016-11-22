#include "stdafx.h"

#include "Time.h"
#include "InputManager.h"
#include "RenderUtil.h"
#include "Window.h"
#include "Game.h"
#include "RenderingEngine.h"

#include "CoreEngine.h"

CoreEngine::CoreEngine(int width, int height, float framerate, Game* game) {
    this->game = game;

    this->width = width;
    this->height = height; 
    this->frameTime = 1.0 / framerate;

    isRunning = false;
}

CoreEngine::~CoreEngine() {
    delete game;
    delete inputManager;
    delete window;

    delete renderingEngine;
}

void CoreEngine::createWindow(string title) {
    window = new Window(width, height, title);
    initRendering();

    renderingEngine = new RenderingEngine();
    inputManager = new InputManager(this);
}

void CoreEngine::start() {
    if (isRunning)return;

    game->init();

    run();
}

void CoreEngine::stop() {
    if (!isRunning)return;

    isRunning = false;
}

GLFWwindow* CoreEngine::getGLFWWindow() {
    return window->getGLFWWindow();
}

InputManager * CoreEngine::getInputManager() {
    return inputManager;
}

void CoreEngine::initRendering() {
    RenderUtil::initGraphics();
    cout << RenderUtil::getOpenGLVersion() << endl;
}

void CoreEngine::run() {
    isRunning = true;

    int frames = 0;
    double frameCounter = 0;

    double lastTime = Time::getTime();
    double unprocessedTime = 0;

    while (isRunning) {
        bool shouldRender = false;

        double startTime = Time::getTime();
        double passedTime = startTime - lastTime;
        lastTime = startTime;

        unprocessedTime += passedTime / (double)(Time::SECOND);
        frameCounter += passedTime;

        while (unprocessedTime > frameTime) {
            shouldRender = true;

            unprocessedTime -= frameTime;

            if (window->isCloseRequested())
                stop();

            glfwPollEvents();
            
            Time::setDelta(frameTime);
            inputManager->update();

            game->update(Time::getDelta(), inputManager);

            if (frameCounter >= Time::SECOND)
            {
                cout << frames << endl;
                frames = 0;
                frameCounter = 0;
            }
        }
        
         if (shouldRender) {
            renderingEngine->render(game->getRootGameObject());
            window->render();
            frames++;
        }
        else {
            Sleep(1);
        }
    }
}
/*
void CoreEngine::render() {
    RenderUtil::clearScreen();
    game->render();
    window->render();
}
*/