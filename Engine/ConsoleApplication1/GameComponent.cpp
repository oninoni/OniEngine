#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"
#include "Shader.h"

#include "GameComponent.h"

GameComponent::GameComponent() {
}

GameComponent::~GameComponent() {
}

void GameComponent::init(Transform * transform) {
}

void GameComponent::update(Transform * transform, const double & delta, InputManager * input) {
}

void GameComponent::render(Transform * transform, Shader * shader, Camera * camera) {
}
