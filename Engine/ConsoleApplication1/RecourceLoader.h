#pragma once

enum FaceMode {
    fM_NAM,
    fM_Vertex,
    fM_VertexTexture,
    fm_VertexNormal,
    fM_VertexTextureNormal
};

struct Image {
public:
    unsigned int width;
    unsigned int height;
    vector<unsigned char> data;
};

class RecourceLoader {
private:
    static Mesh* loadOBJ(string fileName, Shader* shader);

    static Image loadPNG(const char* filename);
public:
    static string loadShader(string fileName);

    static Mesh* loadMesh(string fileName, Shader* shader);

    static Image loadTexture(string fileName);
};