#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"
#include "Shader.h"

#include "GameObject.h"

#include "GameComponent.h"

GameComponent::GameComponent() {
}

void GameComponent::init(GameObject* parent, string name){
    this->parent = parent;
    this->name = name;
}

void GameComponent::update(const double & delta, InputManager * input) {
}

void GameComponent::render(Shader * shader, Camera * camera) {
}

string GameComponent::getName() {
    return name;
}

mat4 GameComponent::getTransformationMatrix(bool inverted) {
    return parent->getTransformationMatrix(inverted);
}