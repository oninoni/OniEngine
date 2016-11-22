#include "stdafx.h"

#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"

#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(Mesh * m, Material * mat) {
    mesh = m;
    material = mat;
}

MeshRenderer::~MeshRenderer() {

}

void MeshRenderer::render(Transform * transform, Shader* shader, Camera* camera) {
    material->bind(shader, 0);
    camera->render(shader, transform->getTransformationMatrix());
    mesh->render();
}
