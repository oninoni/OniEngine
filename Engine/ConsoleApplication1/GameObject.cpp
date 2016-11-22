#include "GameObject.h"

#include "InputManager.h"
#include "GameComponent.h"

GameObject::GameObject() {
    transform = new Transform();
}

GameObject::~GameObject() {
    delete transform;
}

void GameObject::addChild(GameObject* child) {
    children.push_back(child);
}

void GameObject::addComponent(GameComponent* component) {
    components.push_back(component);
    component->init(transform);
}

void GameObject::update(const double & delta, InputManager * input) {
    for (GameComponent* gameComponent : components) {
        gameComponent->update(transform ,delta, input);
    }

    for (GameObject* gameObject : children) {
        gameObject->update(delta, input);
    }
}

void GameObject::render(Shader* shader, Camera* camera) {
    for (GameComponent* gameComponent : components) {
        gameComponent->render(transform, shader, camera);
    }

    for (GameObject* gameObject : children) {
        gameObject->render(shader, camera);
    }
}

Transform* GameObject::getTransform() {
    return transform;
}
