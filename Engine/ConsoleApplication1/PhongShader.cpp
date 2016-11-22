#include "stdafx.h"

#include "PhongShader.h"

PhongShader::PhongShader() : Shader("phong") {
    addAttribute("v_position", GL_FLOAT, 3);
    addAttribute("v_normal", GL_FLOAT, 3);
    addAttribute("v_uv", GL_FLOAT, 2);

    setUniformVec3("l_ambient", vec3(1.0f, 1.0f, 1.0f));
}


PhongShader::~PhongShader() {
}

Shader* PhongShader::getInstance() {
    static PhongShader phongShader;
    return &phongShader;
}
