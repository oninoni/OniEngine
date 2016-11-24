#pragma once

class GameComponent;
class InputManager;
class Camera;
class Shader;

class GameObject {
private:
    Transform transform;

    GameObject* parent;

    vector<GameObject> children;
    vector<GameComponent> components;
public:
    GameObject();
    ~GameObject();

    void addChild(GameObject child);

    void addComponent(GameComponent& component);
    void addComponent(string name, GameComponent& component);
    void removeComponent(string name);
    GameComponent& getComponent(string name);

    void update(const double & delta, InputManager* input);
    void render(Shader* shader, Camera* camera);

    GameObject* getParent();
    void setParent(GameObject* parent);

    mat4 getTransformationMatrix(bool inverted = false);
    Transform& getTransform();
};