#include "stdafx.h"

#include "Attenuation.h"

Attenuation::Attenuation(float range) {
    constant = 1;
    linear = 2 / (range);
    square = 4 / (range*range);
}

Attenuation::Attenuation(float c, float l, float s) {
    constant = c;
    linear = l;
    square = s;
}

float Attenuation::getConstant() {
    return constant;
}

void Attenuation::setConstant(float c) {
    constant = c;
}

float Attenuation::getLinear() {
    return linear;
}

void Attenuation::setLinear(float l) {
    linear = l;
}

float Attenuation::getSquare() {
    return square;
}

void Attenuation::setSquare(float s) {
    square = s;
}
