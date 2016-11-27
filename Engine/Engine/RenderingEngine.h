#pragma once

class Shader;
class Camera;
class Window;
class Texture;

class LightHandler;

class RenderingEngine {
private:
    Window* window;
    Shader* shader;
    Camera* camera;

    void initGraphics();
    const char* getOpenGLVersion();

    inline void setClearColor(vec4 color);
    inline void setClearColor(vec3 color);

public:
    static TextureRenderTarget* tempTarget;

    RenderingEngine(Camera* camera, Window* window);
    ~RenderingEngine();

    void clearScreen();
    void render(GameObject* object);
};