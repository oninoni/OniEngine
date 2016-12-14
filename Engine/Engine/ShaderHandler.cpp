#include "stdafx.h"

#include "Shader.h"
#include "PhongShader.h"
#include "ShadowmapShader.h"

#include "ShaderHandler.h"

ShaderHandler::ShaderHandler() {
    phongShader = new PhongShader();
    shadowmapShader = new ShadowmapShader();
}

ShaderHandler::~ShaderHandler() {
    delete phongShader;
    delete shadowmapShader;
}

PhongShader * ShaderHandler::getPhongShader() {
    return phongShader;
}

ShadowmapShader * ShaderHandler::getShadowmapShader() {
    return shadowmapShader;
}

uint ShaderHandler::getCount() {
    return 2;
}

Shader * ShaderHandler::getShader(uint id) {
    switch (id) {
    case 0:
        return phongShader;
    case 1:
        return shadowmapShader;
    }
}

