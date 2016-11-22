#pragma once

#include "GameComponent.h"

class C_MeshRenderer : public GameComponent {
private:
    Mesh* mesh;
    Material* material;
protected:
public:
    C_MeshRenderer(Mesh* m, Material* mat);
    ~C_MeshRenderer();
    
    void render(GameObject* parent, Shader* shader, Camera* camera);
};