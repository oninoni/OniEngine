#include "MainComponent.h"

const double MainComponent::FRAME_CAP = 5000;

int * MainComponent::argc;
char ** MainComponent::argv;

MainComponent::MainComponent(int * argc, char ** argv) {

    window = new Window(800, 600, "OniEngine");
    cout << RenderUtil::getOpenGLVersion() << endl;
    isRunning = false;

    RenderUtil::initGraphics();

    //InputManager::getInstance();

    game = new Game();
}

MainComponent::~MainComponent() {
    delete game;
    delete window;
}

MainComponent* MainComponent::getInstance(int * argc, char ** argv) {
    MainComponent::argc = argc;
    MainComponent::argv = argv;
    return getInstance();
}

MainComponent* MainComponent::getInstance() {
    static MainComponent mainComponent(argc, argv);
    return &mainComponent;
}

void MainComponent::start() {
    if (isRunning)return;
    run();
}

void MainComponent::stop() {
    if (!isRunning)return;
    cleanUp();

    isRunning = false;
}

GLFWwindow* MainComponent::getGLFWWindow() {
    return window->getGLFWWindow();
}

void MainComponent::run() {
    isRunning = true;

    int frames = 0;
    double frameCounter = 0;

    const double frameTime = 1 / FRAME_CAP;

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
            InputManager::getInstance()->update();

            game->input();
            game->update();

            if (frameCounter >= Time::SECOND)
            {
                cout << frames << endl;
                frames = 0;
                frameCounter = 0;
            }
        }
        
        if (shouldRender) {
            frames++;
            render();
        }
        else {
            Sleep(1);
        }
    }

    cleanUp();
}

void MainComponent::render() {
    RenderUtil::clearScreen();
    game->render();
    window->render();
}

void MainComponent::cleanUp() {
    //window->dispose();
}


