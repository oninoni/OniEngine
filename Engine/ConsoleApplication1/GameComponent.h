#pragma once

class Camera;
class InputManager;

class GameComponent {
protected:
    GameComponent();
    ~GameComponent();
public:
    virtual void init(Transform* transform);
    virtual void update(Transform* transform, const double & delta, InputManager* input);
    virtual void render(Transform* transform, Shader* shader, Camera* camera);
};