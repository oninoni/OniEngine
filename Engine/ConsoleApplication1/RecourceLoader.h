#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

static class RecourceLoader {
public:
    static char* loadShader(string fileName, int &length);
};