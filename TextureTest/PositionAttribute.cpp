#include "PositionAttribute.hpp"

PositionAttribute::PositionAttribute(GLint location) : ShaderAttribute(location)
{
    DefineAttributeArray();
}

void PositionAttribute::DefineAttributeArray()
{
    glVertexAttribPointer(m_location, 2, GL_FLOAT, GL_FALSE,
                          7 * sizeof(GLfloat), 0);
}