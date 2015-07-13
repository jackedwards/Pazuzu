#include "ShaderAttribute.hpp"

ShaderAttribute::ShaderAttribute(GLint location)
{
    m_location = location;
    Enable();
}

void ShaderAttribute::Enable()
{
    glEnableVertexAttribArray(m_location);
}