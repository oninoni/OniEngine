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

Attenuation::Attenuation(float c, float l, float s) {
    constant = c;
    constantChanged = true;
    linear = l;
    linearChanged = true;
    square = s;
    squareChanged = true;
}

void Attenuation::forceUpdate() {
    constantChanged = true;
    linearChanged = true;
    squareChanged = true;
}

float Attenuation::getConstant() {
    return constant;
}

void Attenuation::setConstant(float c) {
    if (constant == c)return;
    constant = c;
    constantChanged = true;
}

float Attenuation::getLinear() {
    return linear;
}

void Attenuation::setLinear(float l) {
    if (linear = l)return;
    linear = l;
    linearChanged = true;
}

float Attenuation::getSquare() {
    return square;
}

void Attenuation::setSquare(float s) {
    if (square == s)return;
    square = s;
    squareChanged = true;
}
