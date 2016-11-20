#include "RecourceLoader.h"

Mesh *RecourceLoader::loadOBJ(string fileName, Shader* shader) {
    vector<vec3> positions;
    vector<vec3> normals;
    vector<vec2> uvs;
    vector<ivec3> indices;

    ifstream file;
    file.open(fileName.c_str());

    string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            vector<string> tokens;

            //cout << line << endl;

            int initialSpaces;
            for (initialSpaces = 0; initialSpaces < line.size(); initialSpaces++) {
                if (line[initialSpaces] != ' ')
                    break;
            }

            line = line.substr(initialSpaces);
            
            int lastPos = -1;
            for (uint i = 0; i < line.size(); i++) {
                if (line[i] == '#')break;
                if (line[i + 1] == ' ' || i == line.size() - 1) {
                    if (line[i] != ' ') {
                        tokens.push_back(line.substr(lastPos + 1, i - lastPos));
                    }
                    lastPos = i + 1;
                }
            }
            if (tokens.size() == 0) {
                //cout << "Skipping Line" << endl;
                continue;
            }

            for (int i = 0; i < tokens.size(); i++) {
                cout << "|" << tokens[i] << "|" << endl;
            }

            if (tokens[0] == "o") {
                //NAME
            }
            else if (tokens[0] == "v") {
                if (tokens.size() >= 4) {
                    vec3 position;
                    position.x = stof(tokens[1]);
                    position.y = stof(tokens[2]);
                    position.z = stof(tokens[3]);
                    //cout << line << " read as " << position << endl;
                    positions.push_back(position);
                }
                else {
                    cerr << "Invalid v statement: " << line << endl;
                }
                continue;
            }
            else if (tokens[0] == "vt") {
                if (tokens.size() >= 3) {
                    vec2 uv;
                    uv.u = stof(tokens[1]);
                    uv.v = stof(tokens[2]);
                    //cout << line << " read as " << uv << endl;
                    uvs.push_back(uv);
                }
                else {
                    cerr << "Invalid vt statement: " << line << endl;
                }
                continue;
                //NEEDS TO BE PUT IN VERTEX
            }
            else if (tokens[0] == "vn") {
                if (tokens.size() >= 4) {
                    vec3 normal;
                    normal.x = stof(tokens[1]);
                    normal.y = stof(tokens[2]);
                    normal.z = stof(tokens[3]);
                    //cout << line << " read as " << normal << endl;
                    normals.push_back(normal);
                }
                else {
                    cerr << "Invalid vn statement: " << line << endl;
                }
                continue;
                //NEEDS TO BE PUT IN VERTEX
            }
            else if (tokens[0] == "g") {
                //GRUPPE
            }
            else if (tokens[0] == "usemtl") {
                //MATERIAL CHANGE
            }
            else if (tokens[0] == "s") {
                //SMOOTHING GROUP
            }
            else if (tokens[0] == "f") {
                if (tokens.size() == 4) {
                    for (int i = 2; i >= 0; i--) { // REVERSE ORDER
                        string vertexIds = tokens[i + 1];
                        vector <string> vertexIdsSplit;

                        //cout << vertexIds << endl; 

                        FaceMode mode = fM_NAM;
                        int SlashCounter = 0;

                        int lastP = -1;
                        for (int j = 0; j < vertexIds.size(); j++) {
                            if (vertexIds[j + 1] == '/' || j == vertexIds.size() - 1) {
                                if (vertexIds[j] != '/')
                                    vertexIdsSplit.push_back(vertexIds.substr(lastP + 1, j - lastP));
                                else {
                                    vertexIdsSplit.push_back("0");
                                    mode = fm_VertexNormal;
                                }
                                lastP = j + 1;
                                if (vertexIds[j + 1] == '/')
                                    SlashCounter++;
                            }
                        }

                        if (mode == fM_NAM) {
                            switch (SlashCounter) {
                            case 0:
                                mode = fM_Vertex;
                                break;
                            case 1:
                                mode = fM_VertexTexture;
                                break;
                            case 2:
                                mode = fM_VertexTextureNormal;
                                break;
                            }
                        }

                        if (mode == fM_NAM) {
                            cerr << "Face invalid: " << line << endl;
                            //break;
                        }
                        
                        ivec3 index;

                        switch (mode) {
                        case fM_Vertex:
                            index.x = stoi(vertexIdsSplit[0]) - 1;
                            break;
                        case fM_VertexTexture:
                            index.x = stoi(vertexIdsSplit[0]) - 1;
                            index.y = stoi(vertexIdsSplit[1]) - 1;
                            break;
                        case fm_VertexNormal:
                            index.x = stoi(vertexIdsSplit[0]) - 1;
                            index.z = stoi(vertexIdsSplit[2]) - 1;
                            break;
                        case fM_VertexTextureNormal:
                            index.x = stoi(vertexIdsSplit[0]) - 1;
                            index.y = stoi(vertexIdsSplit[1]) - 1;
                            index.z = stoi(vertexIdsSplit[2]) - 1;
                            break;
                        }
                        
                        indices.push_back(index);
                        //Per Vertice Materials here too

                        cout << vertexIds << " read as: " << index << endl;
                    }
                }
                else {
                    cerr << "Invalid f statement: " << line << endl;
                }
                continue;
            }
            cerr << "Unknown Line in " << fileName << ": " << line << endl;
        }

        cout << "All is read!" << endl;

        Vertex* verts = new Vertex[indices.size()]();

        for (int i = 0; i < indices.size(); i++) {
            ivec3 index = indices[i];
            verts[i] = Vertex(
                positions[index.x],
                normals[index.z],
                uvs[index.y]
                );
        }

        Mesh* m = new Mesh(shader, verts, indices.size());

        delete[] verts;

        return m;
    }
    else {
        cerr << "Unable to open obj: " << fileName << endl;
    }

    return NULL;
}

string RecourceLoader::loadShader(string fileName) {
    ifstream file;
    file.open(fileName.c_str());

    string output;
    string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else {
        cerr << "Unable to open shader: " << fileName << endl;
    }

    return output;
}

Mesh* RecourceLoader::loadMesh(string fileName, Shader* shader) {
    string format;

    for (int i = fileName.size() - 1; i >= 0; i--) {
        if (fileName.at(i) == '.') {
            format = fileName.substr(i + 1);
        }
    }

    transform(format.begin(), format.end(), format.begin(), tolower);

    if (format == "obj") {
        return loadOBJ(fileName, shader);
    }

    cerr << "File: " << fileName << " could not be loaded by the Engine. Object Format not supported!" << endl;

    return NULL;
}

Image RecourceLoader::loadTexture(string fileName) {
    string format;

    for (int i = fileName.size() - 1; i >= 0; i--) {
        if (fileName.at(i) == '.') {
            format = fileName.substr(i + 1);
        }
    }

    transform(format.begin(), format.end(), format.begin(), tolower);

    if (format == "obj") {
        return loadPNG(fileName.c_str());
    }

    cerr << "File: " << fileName << " could not be loaded by the Engine. Texture Format not supported!" << endl;

    return Image();
}

Image RecourceLoader::loadPNG(const char * filename) {
    Image image;

    //decode
    unsigned error = lodepng::decode(image.data, image.width, image.height, filename);

    //if there's an error, display it
    if (error)
        cout << "decoder error " << error << ": " << lodepng_error_text(error) << endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...


    return image;
}