#include "stdafx.h"

#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

#include "C_MeshRenderer.h"

C_MeshRenderer::C_MeshRenderer(Mesh * m, Material * mat) {
    mesh = m;
    material = mat;
}

C_MeshRenderer::~C_MeshRenderer() {

}

void C_MeshRenderer::render(GameObject* parent, Shader* shader, Camera* camera) {
    material->bind(shader, 0);
    camera->render(shader, getTransformationMatrix(parent));
    mesh->render();
}