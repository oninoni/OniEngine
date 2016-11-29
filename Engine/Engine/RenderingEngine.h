#pragma once

class Shader;
class Camera;
class Window;

class LightHandler;

class TextureArrayFramebuffer;

class RenderingEngine {
private:
    Window* window;
    Shader* shader;
    Camera* camera;
    
    LightHandler* lightHandler;

    void initGraphics();
    const char* getOpenGLVersion();

    inline void setClearColor(vec4 color);
    inline void setClearColor(vec3 color);

public:
    RenderingEngine(Camera* camera, Window* window);
    ~RenderingEngine();

    static void clearScreen();
    void render(GameObject* object);
};