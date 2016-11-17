#pragma once

class Game;

#include "Time.h"
#include "InputManager.h"
#include "Window.h"
#include "Game.h"

#include <Windows.h>


class MainComponent {
private:
    Window* window;
    bool isRunning;

    Game* game;

    void run();
    void render();
    void cleanUp();

    static int * argc;
    static char ** argv;
public:
    static MainComponent*  getInstance();
    static MainComponent*  getInstance(int * argc, char ** argv);

    static const double FRAME_CAP;

    MainComponent(int * argc, char ** argv);
    ~MainComponent();

    void start();
    void stop();

    GLFWwindow* getGLFWWindow();
};