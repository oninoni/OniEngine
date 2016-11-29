#include "stdafx.h"

#include "Shader.h"

#include "Attenuation.h"

Attenuation::Attenuation(float range) {
    constant = 1;
    constantChanged = true;
    linear = 2 / (range);
    linearChanged = true;
    square = 4 / (range*range);
    squareChanged = true;
}

Attenuation::Attenuation(float constant, float linear, float square) {
    this->constant = constant;
    this->constantChanged = true;

    this->linear = linear;
    this->linearChanged = true;

    this->square = square;
    this->squareChanged = true;
}

void Attenuation::forceUpdate() {
    constantChanged = true;
    linearChanged = true;
    squareChanged = true;
}

float Attenuation::getConstant() {
    return constant;
}

void Attenuation::setConstant(float constant) {
    if (this->constant == constant)return;

    this->constant = constant;
    constantChanged = true;
}

float Attenuation::getLinear() {
    return linear;
}

void Attenuation::setLinear(float linear) {
    if (this->linear = linear)return;

    this->linear = linear;
    linearChanged = true;
}

float Attenuation::getSquare() {
    return square;
}

void Attenuation::setSquare(float square) {
    if (this->square == square)return;

    this->square = square;
    squareChanged = true;
}
