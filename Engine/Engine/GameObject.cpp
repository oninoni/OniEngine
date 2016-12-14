#include "stdafx.h"

#include "Camera.h"
#include "Shader.h"

#include "InputManager.h"
#include "GameComponent.h"

#include "LightHandler.h"

#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
    if(parent)
       parent->removeChild(this);

    for (GameComponent* gameComponent : components) {
        gameComponent->c_destroy();
        gameComponent->setParent(NULL);
        delete gameComponent;
    }

    for (GameObject* child : children) {
        child->parent = NULL;
        delete child;
    }
}

void GameObject::addChild(GameObject* child) {
    child->init(this);
    children.insert(child);
}

void GameObject::removeChild(GameObject* child) {
    children.erase(child);
}

void GameObject::addComponent(GameComponent* component) {
    component->init(this);
    components.insert(component);
}

void GameObject::removeComponent(GameComponent* component) {
    components.erase(component);
}

void GameObject::init(GameObject * parent) {
    this->parent = parent;
}

void GameObject::update(const double & delta, InputManager * input) {
    for (GameComponent* gameComponent : components)
        gameComponent->update(delta, input);

    for (GameObject* child : children)
        child->update(delta, input);
}

void GameObject::preRender(LightHandler* lightHandler, Shader * shader) {
    for (GameComponent* gameComponent : components)
        gameComponent->preRender(lightHandler, shader);

    for (GameObject* child : children)
        child->preRender(lightHandler, shader);
}

void GameObject::render(Shader* shader, Camera* camera) {
    for (GameComponent* gameComponent : components)
        gameComponent->render(shader, camera);

    for (GameObject* child : children)
        child->render(shader, camera);
}

Transform& GameObject::getTransform() {
    return transform;
}

mat4 GameObject::getTransformationMatrix(bool inverted) {
    if (!parent)
        return getTransform().getTransformationMatrix(inverted);
    else
        if(inverted)
            return transform.getTransformationMatrix(inverted) * parent->getTransformationMatrix(inverted);
        else
            return parent->getTransformationMatrix(inverted) * transform.getTransformationMatrix(inverted);
}