#pragma once

class BaseLight;
class Attenuation;

class DirectionalLight;
class PointLight;
class SpotLight;

enum ShaderType{
    VertexShader,
    GeometryShader,
    FragmentShader,

    NUM_SHADERS
};

struct GLSLAttribute {
    GLuint location;
    GLuint size;
    GLenum type;
    int offset;
};

class Shader {
private:
    vector<GLSLAttribute> attributes;
    int stride;

    unordered_map<string, int> uniforms;
    
    GLuint program;
    GLuint shaders[NUM_SHADERS];

    void addUniform(string uniform);

    static GLuint createShader(const string& text, GLenum type);
    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

    void setUniformBLight(string uniformLocation, BaseLight * baseLight);
    void setUniformAttend(string uniformLocation, Attenuation* attenuation);
public:
    Shader(const string& fileName);
    void bind();
    ~Shader();

    void addAttribute(string name, GLenum type, int size);
    GLSLAttribute getGLSLAttribute(int i);
    int getGLSLAttributeCount();
    int getGLSLALSKJFHJKADSHFJKSDHFJKHSTride();

    GLint getUniformLocation(string uniform);

    void setUniformI(string uniformLocation, int value);
    void setUniformF(string uniformLocation, float value);
    void setUniformVec3(string uniformLocation, vec3 value);
    void setUniformVec4(string uniformLocation, vec4 value);
    void setUniformMat4(string uniformLocation, mat4 value, GLboolean transpose = GL_FALSE);

    void setUniformDLight(string uniformLocation, DirectionalLight* directionalLight);
    void setUniformPLight(string uniformLocation, PointLight* pointLight);
    void setUniformSLight(string uniformLocation, SpotLight* spotLight);
};