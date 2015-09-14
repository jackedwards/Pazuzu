#include "ShaderAttribute.hpp"

/**
 * @brief Sets the location of the attribute and
 *        enables the vertex attribute array
 */
ShaderAttribute::ShaderAttribute(GLint location)
{
    m_location = location;
    Enable();
}

/**
 * @brief Enables the vertex attribute array
 */
void ShaderAttribute::Enable()
{
    glEnableVertexAttribArray(m_location);
}