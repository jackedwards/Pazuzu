#include "ColorAttribute.hpp"

ColorAttribute::ColorAttribute(GLint location) : ShaderAttribute(location)
{
    DefineAttributeArray();
}

void ColorAttribute::DefineAttributeArray()
{
    glVertexAttribPointer(m_location, 3, GL_FLOAT, GL_FALSE,
                          7 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
}