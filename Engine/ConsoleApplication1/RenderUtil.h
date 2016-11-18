#pragma once
#pragma once

#include "OpenGL.h"

static class RenderUtil {
public:
    static void clearScreen();
    static void initGraphics();
    const static char* getOpenGLVersion();
};