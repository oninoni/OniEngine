#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"
#include "Shader.h"

#include "GameObject.h"

#include "GameComponent.h"

GameComponent::GameComponent() {
}

GameComponent::~GameComponent() {
    if(parent)
        parent->removeComponent(this);
}

void GameComponent::init(GameObject* parent){
    c_init(parent);
    this->parent = parent;
}

void GameComponent::update(const double & delta, InputManager * input) {
    c_update(delta, input);
}

void GameComponent::preRender(Shader * shader) {
    c_preRender(shader);
}

void GameComponent::render(Shader * shader, Camera * camera) {
    c_render(shader, camera);
}

void GameComponent::setParent(GameObject * parent) {
    this->parent = parent;
}

mat4 GameComponent::getTransformationMatrix(bool inverted) {
    return parent->getTransformationMatrix(inverted);
}