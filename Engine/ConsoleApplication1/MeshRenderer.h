#pragma once

#include "stdafx.h"

#include "GameComponent.h"

class Material;
class Mesh;
class Shader;
class Camera;

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

