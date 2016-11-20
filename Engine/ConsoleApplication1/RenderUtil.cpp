#include "RenderUtil.h"

void RenderUtil::clearScreen() {
    //TODO Stencil Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::initGraphics() {
    glClearColor(0, 0, 0, 0);

    // Clockwise is front
    glFrontFace(GL_CCW);

    //Culling Back
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);

    //Enable z component on render result
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_DEPTH_CLAMP);
}

const char* RenderUtil::getOpenGLVersion() {
    return (char*)glGetString(GL_VERSION);
}

void RenderUtil::setClearColor(vec4 color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

inline void RenderUtil::setClearColor(vec3 color) {
    glClearColor(color.r, color.g, color.b, 1.0);
}
