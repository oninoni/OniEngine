#pragma once

class GameComponent;
class InputManager;
class Camera;
class Shader;

class GameObject {
private:
    Transform* transform;

    GameObject* parent;
    vector<GameObject*> children;

    vector<GameComponent*> components;
public:
    GameObject();
    ~GameObject();

    void addChild(GameObject* child);
    void addComponent(GameComponent* component);

    void update(const double & delta, InputManager* input);
    void render(Shader* shader, Camera* camera);

    Transform* getRelativeTransform();
    Transform* getTransform();

    GameObject* getParent();
    void setParent(GameObject* parent);
};