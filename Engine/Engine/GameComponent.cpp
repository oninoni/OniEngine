#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"

#include "GameObject.h"

#include "ShaderHandler.h"
#include "LightHandler.h"

#include "GameComponent.h"

GameComponent::GameComponent() {
}

GameComponent::~GameComponent() {
    if(parent)
        parent->removeComponent(this);

    this->c_destroy();
    this->setParent(NULL);
}

void GameComponent::init(GameObject* parent){
    c_init(parent);
    this->parent = parent;
}

void GameComponent::update(const double & delta, InputManager * input) {
    c_update(delta, input);
}

void GameComponent::preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    c_preRender(shaderHandler, lightHandler, shadowRender);
}

void GameComponent::render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
    c_render(shaderHandler, camera, shadowRender);
}

void GameComponent::setParent(GameObject * parent) {
    this->parent = parent;
}

mat4 GameComponent::getTransformationMatrix(bool inverted) {
    return parent->getTransformationMatrix(inverted);
}