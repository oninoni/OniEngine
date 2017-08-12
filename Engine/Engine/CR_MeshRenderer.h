#pragma once

#include "GameProperty.h"

class CR_MeshRenderer : public GameProperty {
private:
    Mesh* mesh;
    Material* material;
protected:
public:
    CR_MeshRenderer(Mesh* m, Material* mat);

    string GetDafaultName();
    
    void c_render(ShaderHandler* shaderHandler, Camera* camera, bool shadowRender = false);
};