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

void GameComponent::init(GameObject* parent){
    this->parent = parent;
}

void GameComponent::update(const double & delta, InputManager * input) {
}

void GameComponent::render(Shader * shader, Camera * camera) {
}

mat4 GameComponent::getTransformationMatrix(bool inverted) {
    return parent->getTransformationMatrix(inverted);
}