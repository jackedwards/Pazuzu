#ifndef SHADERATTRIBUTE_HPP
#define SHADERATTRIBUTE_HPP

#include <GL/glew.h>

class ShaderAttribute
{
protected:
    GLint m_location;

public:
    ShaderAttribute(GLint location);
    virtual ~ShaderAttribute() = 0;
private:
    void Enable();
};

inline ShaderAttribute::~ShaderAttribute() {};

#endif
