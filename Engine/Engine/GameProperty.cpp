#include "stdafx.h"

#include "InputManager.h"
#include "Camera.h"

#include "GameObject.h"

#include "ShaderHandler.h"
#include "LightHandler.h"

#include "GameProperty.h"

GameProperty::GameProperty() {
}

GameProperty::~GameProperty() {
    if(parent)
        parent->removeProperty(this);

    this->c_destroy();
    this->setParent(NULL);
}

void GameProperty::init(GameObject* parent){
    c_init(parent);
    this->parent = parent;
}

void GameProperty::update(const double & delta, InputManager * input) {
    c_update(delta, input);
}

void GameProperty::preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender) {
    c_preRender(shaderHandler, lightHandler, shadowRender);
}

void GameProperty::render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
    c_render(shaderHandler, camera, shadowRender);
}

void GameProperty::setParent(GameObject * parent) {
    this->parent = parent;
}

mat4 GameProperty::getTransformationMatrix(bool inverted) {
    return parent->getTransformationMatrix(inverted);
}