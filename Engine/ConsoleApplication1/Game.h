#pragma once

#include "InputManager.h"
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    void input();
    void update();
    void render();
};

