#include "VertexShader.hpp"

VertexShader::VertexShader(const std::string& source)
{
    m_shader = glCreateShader(GL_VERTEX_SHADER);
    SetSource(source);
    Compile();
}