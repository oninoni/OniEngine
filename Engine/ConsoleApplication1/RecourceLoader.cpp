#include "RecourceLoader.h"

string RecourceLoader::loadShader(string fileName) {
    ifstream file;
    file.open((fileName).c_str());

    string output;
    string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else {
        cerr << "Unable to load shader: " << fileName << endl;
    }

    return output;
}