#include "stdafx.h"

#include "PhongShader.h"

PhongShader::PhongShader() : Shader("phong") {
    addAttribute("v_position", GL_FLOAT, 3);
    addAttribute("v_normal", GL_FLOAT, 3);
    addAttribute("v_uv", GL_FLOAT, 2);
    addAttribute("v_tangent", GL_FLOAT, 3);
    addAttribute("v_biTangent", GL_FLOAT, 3);

    setUniformVec3("l_ambient", vec3(0.1f));
}

PhongShader::~PhongShader() {
}