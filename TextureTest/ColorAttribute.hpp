#ifndef COLORATTRIBUTE_HPP
#define COLORATTRIBUTE_HPP

#include "ShaderAttribute.hpp"

class ColorAttribute : public ShaderAttribute
{
public:
    ColorAttribute(GLint location);
private:
    void DefineAttributeArray();
};

#endif
