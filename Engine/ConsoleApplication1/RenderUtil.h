#pragma once

#include "OpenGL.h"

class RenderUtil {
public:
    static void clearScreen();
    static void initGraphics();
    const static char* getOpenGLVersion();
};