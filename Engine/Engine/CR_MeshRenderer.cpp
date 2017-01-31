#include "stdafx.h"

#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

#include "ShaderHandler.h"

#include "CR_MeshRenderer.h"

CR_MeshRenderer::CR_MeshRenderer(Mesh * m, Material * mat) {
    mesh = m;
    material = mat;
}

string CR_MeshRenderer::GetDafaultName() {
    return "C_MeshRenderer";
}

void CR_MeshRenderer::c_render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender) {
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