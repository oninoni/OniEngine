#pragma once

#include "stdafx.h"

class RenderUtil {
public:
    static void clearScreen();
    static void initGraphics();
    const static char* getOpenGLVersion();
    inline static void setClearColor(vec4 color);
    inline static void setClearColor(vec3 color);
};