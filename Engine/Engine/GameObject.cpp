#include "stdafx.h"

#include "Camera.h"

#include "InputManager.h"
#include "GameComponent.h"

#include "ShaderHandler.h"
#include "LightHandler.h"

#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
    if(parent)
       parent->removeChild(this);

    for (GameComponent* gameComponent : components) {
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

void GameObject::preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    for (GameComponent* gameComponent : components)
        gameComponent->preRender(shaderHandler, lightHandler, shadowRender);

    for (GameObject* child : children)
        child->preRender(shaderHandler, lightHandler, shadowRender);
}

void GameObject::render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
    for (GameComponent* gameComponent : components)
        gameComponent->render(shaderHandler, camera, shadowRender);

    for (GameObject* child : children)
        child->render(shaderHandler, camera, shadowRender);
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