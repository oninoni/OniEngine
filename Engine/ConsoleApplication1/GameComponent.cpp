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

void GameComponent::init(GameObject* parent) {
}

void GameComponent::update(GameObject* parent, const double & delta, InputManager * input) {
}

void GameComponent::render(GameObject* parent, Shader * shader, Camera * camera) {
}

Transform& GameComponent::getTransform() {
    return transform;
}

mat4 GameComponent::getTransformationMatrix(GameObject* parent, bool inverted) {
    if(inverted)
        return transform.getTransformationMatrix(inverted) * parent->getTransformationMatrix(inverted);
    else
        return parent->getTransformationMatrix(inverted) * transform.getTransformationMatrix(inverted);
}