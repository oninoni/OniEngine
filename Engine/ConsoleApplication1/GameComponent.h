#pragma once

class Camera;
class Shader;
class InputManager;
class GameObject;

class GameComponent {
private:
    GameObject* parent;
protected:
    GameComponent();
    ~GameComponent();

    inline Transform* getTransform();
public:
    virtual void init();
    virtual void update(const double & delta, InputManager* input);
    virtual void render(Shader* shader, Camera* camera);

    GameObject* getParent();
    void setParent(GameObject* parent);

};