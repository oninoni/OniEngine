#pragma once

class Shader;
class Camera;

class RenderingEngine {
private:
    Shader* shader;
    Camera* camera;

    void initGraphics();
    const char* getOpenGLVersion();

    inline void setClearColor(vec4 color);
    inline void setClearColor(vec3 color);

public:
    RenderingEngine();
    ~RenderingEngine();

    void clearScreen();
    void render(GameObject* object);
};

