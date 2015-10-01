#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <GL/glew.h>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

class ShaderProgram
{
private:
    GLuint m_id;

public:
    ShaderProgram();
    ShaderProgram(VertexShader& vert, FragmentShader& frag);
	~ShaderProgram();
    void Attach(Shader& shader);
    void Use();
    void Delete();
    GLint GetAttribLocation(const std::string& name);
	GLint GetUniformLocation(const std::string& name);
};

#endif