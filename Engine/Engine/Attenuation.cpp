#include "stdafx.h"

#include "Shader.h"

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

void Attenuation::setUniformAttenuation(Shader* shader, string uniformLocation) {
    shader->setUniformF(uniformLocation + ".attend_constant", constant);
    shader->setUniformF(uniformLocation + ".attend_linear", linear);
    shader->setUniformF(uniformLocation + ".attend_square", square);
}