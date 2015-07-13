#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <GL/glew.h>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

class ShaderProgram
{
private:
    GLuint m_program;

public:
    ShaderProgram();
    ShaderProgram(VertexShader& vert);
    ShaderProgram(VertexShader& vert, FragmentShader& frag);
    void Attach(Shader& shader);
    void Link();
    void Use();
    void Delete();
    GLint GetAttribute(const std::string& name);
};

#endif
