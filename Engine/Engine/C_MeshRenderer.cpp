#include "stdafx.h"

#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

#include "ShaderHandler.h"

#include "C_MeshRenderer.h"

C_MeshRenderer::C_MeshRenderer(Mesh * m, Material * mat) {
    mesh = m;
    material = mat;
}

string C_MeshRenderer::GetDafaultName() {
    return "C_MeshRenderer";
}

void C_MeshRenderer::c_render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
    Shader* shader;
    if (shadowRender) {
        shader = (Shader*)shaderHandler->getShadowmapShader();
    }
    else {
        shader = (Shader*) shaderHandler->getPhongShader();
    }

    material->bind(shader, 0);
    camera->render(shader, getTransformationMatrix());
    mesh->render();
}