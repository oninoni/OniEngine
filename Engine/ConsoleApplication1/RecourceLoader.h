#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

static class RecourceLoader {
public:
    static string loadShader(string fileName);
};