#pragma once

class CoreEngine {
private:
    int width, height;
    float frameTime;

    Window* window;
    bool isRunning;

    InputManager* inputManager;
    Game* game;

    RenderingEngine* renderingEngine;

    void initRendering();

    void run();
    void render();
    void cleanUp();
public:
    CoreEngine(int width, int height, float framerate, Game* game);
    ~CoreEngine();

    void createWindow(string title);

    void start();
    void stop();

    GLFWwindow* getGLFWWindow();
    InputManager* getInputManager();
};