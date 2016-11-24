#pragma once

class GameComponent;
class InputManager;
class Camera;
class Shader;

class GameObject {
private:
    Transform transform;

    GameObject* parent;

    unordered_set<GameObject*> children;
    unordered_set<GameComponent*> components;
public:
    GameObject();
    ~GameObject();

    void addChild(GameObject* child);
    void removeChild(GameObject* child);

    void addComponent(GameComponent* component);
    void removeComponent(GameComponent* component);

    void init(GameObject* parent);
    void update(const double & delta, InputManager* input);
    void preRender(Shader* shader);
    void render(Shader* shader, Camera* camera);

    mat4 getTransformationMatrix(bool inverted = false);
    Transform& getTransform();
};