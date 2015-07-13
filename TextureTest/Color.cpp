#include "Color.hpp"

const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);

// Forward declared for use in Normalise()
Color operator/(const Color& left, const GLfloat right);

Color::Color() : r(1.0f), g(1.0f), b(1.0f)
{
    
}

Color::Color(GLfloat R, GLfloat G, GLfloat B) : r(R), g(G), b(B)
{
    
}

Color Color::Normalise() const
{
    return (*this) / 255;
}

Color operator/(const Color& left, const GLfloat right)
{
    return Color(left.r / 255,
            left.g / 255,
            left.b / 255);
}