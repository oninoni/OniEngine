#pragma once

#include "OpenGL.h"

class Time {
private:
    static double delta;
public:
    static const double SECOND;

    static double getTime();

    static double getDelta();
    static void setDelta(double delta);
};
