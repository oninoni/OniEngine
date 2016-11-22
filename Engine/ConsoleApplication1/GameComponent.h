#pragma once

class Camera;
class Shader;
class InputManager;

class GameObject;

class GameComponent {
private:
    Transform transform;
protected:
    GameComponent();
    ~GameComponent();
public:
    virtual void init(GameObject* parent);
    virtual void update(GameObject* parent, const double & delta, InputManager* input);
    virtual void render(GameObject* parent, Shader* shader, Camera* camera);

    mat4 getTransformationMatrix(GameObject* parent, bool inverted = false);
    Transform& GameComponent::getTransform();
};