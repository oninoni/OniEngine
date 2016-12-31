#pragma once

class Camera;
class InputManager;
class ShaderHandler;
class LightHandler;
class GameObject;

class GameComponent abstract {
protected:
    GameComponent();

    GameObject* parent;
public:
    ~GameComponent();

    void init(GameObject* parent);
    void update(const double & delta, InputManager* input);
    void preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender = false);
    void render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender = false);

    virtual void c_init(GameObject* parent) {}
    virtual void c_update(const double & delta, InputManager* input) {}
    virtual void c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender = false) {}
    virtual void c_render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender = false) {}
    virtual void c_destroy() {}

    void setParent(GameObject* parent);

    mat4 getTransformationMatrix(bool inverted = false);
};