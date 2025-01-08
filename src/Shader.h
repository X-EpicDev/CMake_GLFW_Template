#pragma once

#include <unordered_map>

class Shader {
private:
    unsigned int id;

public:
    Shader(const std::string &vertexSource, const std::string &fragmentSource);
    ~Shader();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int CreateShader(unsigned int shaderType, const std::string &shaderSource);
    void SetShaderSource(unsigned int shaderId, const std::string &shaderSource);
    bool CompileShader(unsigned int shaderId);
    unsigned int CreateProgram(unsigned int vertexShaderId, unsigned int fragmentShaderId);
    bool LinkProgram(unsigned int id);
};