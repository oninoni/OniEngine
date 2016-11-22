#pragma once

#include "stdafx.h"

#include "Game.h"

class InputManager;


class TestGame : public Game{
private:

public:
    TestGame();
    ~TestGame();

    void init();
    //void update(const double & delta, InputManager* input);
};

