#include <string>
#include <glad/glad.h>
#include "Shader.h"

Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource) {
    unsigned int vertexShaderId = CreateShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShaderId = CreateShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (vertexShaderId != 0 && fragmentShaderId != 0) {
        id = CreateProgram(vertexShaderId, fragmentShaderId);
    } else {
        fprintf(stderr, "Could not create shader program\n");
    }
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::Bind() const {
    glUseProgram(id);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

unsigned int Shader::CreateShader(unsigned int shaderType, const std::string &shaderSource) {
    unsigned int shaderId = glCreateShader(shaderType);
    SetShaderSource(shaderId, shaderSource);
    bool compiled = CompileShader(shaderId);
    if (compiled) {
        return shaderId;
    } else {
        glDeleteShader(shaderId);
        return 0;
    }
}

void Shader::SetShaderSource(unsigned int shaderId, const std::string &shaderSource) {
    char *source = (char *) shaderSource.c_str();
    unsigned int count = 1;
    int *length = nullptr;
    glShaderSource(shaderId, count, &source, length);
}

bool Shader::CompileShader(unsigned int shaderId) {
    glCompileShader(shaderId);
    int status = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
    bool compiled = status != 0;
    if (!compiled) {
        fprintf(stderr, "Could not compile shader\n");
    }
    return compiled;
}

unsigned int Shader::CreateProgram(unsigned int vertexShaderId, unsigned int fragmentShaderId) {
    unsigned int programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    bool linked = LinkProgram(programId);
    if (linked) {
        glDetachShader(programId, vertexShaderId);
        glDetachShader(programId, fragmentShaderId);
        return programId;
    } else {
        glDeleteProgram(programId);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        return 0;
    }
}

bool Shader::LinkProgram(unsigned int programId) {
    glLinkProgram(programId);
    int status = 0;
    glGetProgramiv(programId, GL_LINK_STATUS, (int *) &status);
    bool linked = status != 0;
    if (!linked) {
        fprintf(stderr, "Could not link shader program\n");
    }
    return linked;
}