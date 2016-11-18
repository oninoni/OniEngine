#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class RecourceLoader {
public:
    static string loadShader(string fileName);
};