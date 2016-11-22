#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"
#include "Shader.h"

#include "GameObject.h"
#include "GameComponent.h"

GameComponent::GameComponent() {
}

GameComponent::~GameComponent() {
}

void GameComponent::init() {
}

void GameComponent::update(const double & delta, InputManager * input) {
}

void GameComponent::render(Shader * shader, Camera * camera) {
}

GameObject * GameComponent::getParent() {
    return parent;
}

void GameComponent::setParent(GameObject * parent) {
    this->parent = parent;
}

Transform * GameComponent::getTransform() {
    return parent->getTransform();
}
