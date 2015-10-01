#include "ColorAttribute.hpp"

/**
 * @brief Enables the vertex attribute array and defines
 *        an array of generic vertex attribute data
 */
ColorAttribute::ColorAttribute(GLint location) : ShaderAttribute(location)
{
    glVertexAttribPointer(m_location, 3, GL_FLOAT, GL_FALSE,
                          7 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
}