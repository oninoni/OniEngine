#include "stdafx.h"

#include "Camera.h"
#include "Shader.h"

#include "InputManager.h"
#include "GameComponent.h"

#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

void GameObject::addChild(GameObject* child) {
    child->setParent(this);
    children.push_back(child);
}

void GameObject::addComponent(GameComponent* component) {
    components.push_back(component);
    component->init(this);
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

Transform& GameObject::getTransform() {
    return transform;
}

mat4 GameObject::getTransformationMatrix(bool inverted) {
    if (parent == NULL)
        return getTransform().getTransformationMatrix(inverted);
    else
        if(inverted)
            return transform.getTransformationMatrix(inverted) * parent->getTransformationMatrix(inverted);
        else
            return parent->getTransformationMatrix(inverted) * transform.getTransformationMatrix(inverted);
}

GameObject * GameObject::getParent() {
    return parent;
}

void GameObject::setParent(GameObject * parent) {
    this->parent = parent;
}
