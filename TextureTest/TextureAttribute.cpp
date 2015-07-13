#include "TextureAttribute.hpp"

TextureAttribute::TextureAttribute(GLint location) : ShaderAttribute(location)
{
    DefineAttributeArray();
}

void TextureAttribute::DefineAttributeArray()
{
    glVertexAttribPointer(m_location, 2, GL_FLOAT, GL_FALSE,
                          7 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
}