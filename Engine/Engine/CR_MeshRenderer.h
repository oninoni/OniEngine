#pragma once

#include "GameComponent.h"

class CR_MeshRenderer : public GameComponent {
private:
    Mesh* mesh;
    Material* material;
protected:
public:
    CR_MeshRenderer(Mesh* m, Material* mat);

    string GetDafaultName();
    
    void c_render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender = false);
};