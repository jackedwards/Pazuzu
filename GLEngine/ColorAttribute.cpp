#include "ColorAttribute.hpp"

/**
 * @brief Enables the vertex attribute array and defines
 *        an array of generic vertex attribute data
 */
ColorAttribute::ColorAttribute(GLint location) : ShaderAttribute(location)
{
    glVertexAttribPointer(m_location, 3, GL_FLOAT, GL_FALSE,
                          8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
}