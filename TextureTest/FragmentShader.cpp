#include "FragmentShader.hpp"

FragmentShader::FragmentShader(const std::string& source)
{
    m_shader = glCreateShader(GL_FRAGMENT_SHADER);
    SetSource(source);
    Compile();
}