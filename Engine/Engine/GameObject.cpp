#include "stdafx.h"

#include "Camera.h"

#include "InputManager.h"
#include "GameProperty.h"

#include "ShaderHandler.h"
#include "LightHandler.h"

#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
    if(parent)
       parent->removeChild(this);

    for (GameProperty* prop : properties) {
        delete prop;
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

void GameObject::addProperty(GameProperty* property) {
    property->init(this);
    properties.insert(property);
}

void GameObject::removeProperty(GameProperty* property) {
    properties.erase(property);
}

void GameObject::init(GameObject * parent) {
    this->parent = parent;
}

void GameObject::update(const double & delta, InputManager * input) {
    for (GameProperty* prop : properties)
        prop->update(delta, input);

    for (GameObject* child : children)
        child->update(delta, input);
}

void GameObject::preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    for (GameProperty* prop : properties)
        prop->preRender(shaderHandler, lightHandler, shadowRender);

    for (GameObject* child : children)
        child->preRender(shaderHandler, lightHandler, shadowRender);
}

void GameObject::render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
    for (GameProperty* prop : properties)
        prop->render(shaderHandler, camera, shadowRender);

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