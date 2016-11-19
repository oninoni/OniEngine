#pragma once

class Mesh;


#include <Windows.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Mesh.h"
#include "Shader.h"

using namespace std;

class RecourceLoader {
private:
    static Mesh* loadOBJ(string fileName, Shader* shader);
public:
    static string loadShader(string fileName);

    static Mesh* loadMesh(string fileName, Shader* shader);
};