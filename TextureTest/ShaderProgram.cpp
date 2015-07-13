#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram()
{
    m_program = glCreateProgram();
}

ShaderProgram::ShaderProgram(VertexShader& vert)
{
    m_program = glCreateProgram();
    glAttachShader(m_program, vert.m_shader);
    glLinkProgram(m_program);
    glUseProgram(m_program);
}

ShaderProgram::ShaderProgram(VertexShader& vert, FragmentShader& frag)
{
    m_program = glCreateProgram();
    glAttachShader(m_program, vert.m_shader);
    glAttachShader(m_program, frag.m_shader);
    glLinkProgram(m_program);
    glUseProgram(m_program);
}

void ShaderProgram::Attach(Shader& shader)
{
    glAttachShader(m_program, shader.m_shader);
}

void ShaderProgram::Link()
{
    glLinkProgram(m_program);
}

void ShaderProgram::Use()
{
    glUseProgram(m_program);
}

void ShaderProgram::Delete()
{
    glDeleteProgram(m_program);
}

GLint ShaderProgram::GetAttribute(const std::string& name)
{
    return glGetAttribLocation(m_program, name.c_str());
}