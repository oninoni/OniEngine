#pragma once

#include "GameComponent.h"

class MeshRenderer : public GameComponent {
private:
    Mesh* mesh;
    Material* material;
protected:
public:
    MeshRenderer(Mesh* m, Material* mat);
    ~MeshRenderer();
    
    void render(Transform * transform, Shader* shader, Camera* camera);
};

