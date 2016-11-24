#pragma once

#include "Shader.h"

class LightHandler;

class PhongShader : public Shader {
public:
    PhongShader();
    ~PhongShader();

    static PhongShader* getInstance();
};

