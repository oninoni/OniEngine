#pragma once

#include "GameComponent.h"

class C_MeshRenderer : public GameComponent {
private:
    Mesh* mesh;
    Material* material;
protected:
public:
    C_MeshRenderer(Mesh* m, Material* mat);

    string GetDafaultName();
    
    void c_render(Shader* shader, Camera* camera);
};