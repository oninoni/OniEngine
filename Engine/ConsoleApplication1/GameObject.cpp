#include "stdafx.h"

#include "Camera.h"
#include "Shader.h"

#include "InputManager.h"
#include "GameComponent.h"

#include "GameObject.h"

GameObject::GameObject() {
    transform = new Transform();
}

GameObject::~GameObject() {
    delete transform;
}

void GameObject::addChild(GameObject* child) {
    child->setParent(this);
    children.push_back(child);
}

void GameObject::addComponent(GameComponent* component) {
    component->setParent(this);
    components.push_back(component);
    component->init();
}

void GameObject::update(const double & delta, InputManager * input) {
    for (GameComponent* gameComponent : components) {
        gameComponent->update(delta, input);
    }

    for (GameObject* gameObject : children) {
        gameObject->update(delta, input);
    }
}

void GameObject::render(Shader* shader, Camera* camera) {
    for (GameComponent* gameComponent : components) {
        gameComponent->render(shader, camera);
    }

    for (GameObject* gameObject : children) {
        gameObject->render(shader, camera);
    }
}

Transform* GameObject::getRelativeTransform() {
    return transform;
}

Transform * GameObject::getTransform() {
    return &(*(getParent()->getTransform()) + *transform);
}

GameObject * GameObject::getParent() {
    return parent;
}

void GameObject::setParent(GameObject * parent) {
    this->parent = parent;
}
