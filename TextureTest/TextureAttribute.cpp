#include "TextureAttribute.hpp"

/**
 * @brief Enables the vertex attribute array and defines
 *        an array of generic vertex attribute data
 */
TextureAttribute::TextureAttribute(GLint location) : ShaderAttribute(location)
{
    glVertexAttribPointer(m_location, 2, GL_FLOAT, GL_FALSE,
                          7 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
}