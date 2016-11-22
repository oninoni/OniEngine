#pragma once

#include "Shader.h"

class PhongShader : public Shader {
public:
    PhongShader();
    ~PhongShader();

    static Shader* getInstance();
};

