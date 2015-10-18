#ifndef COLOR_HPP
#define COLOR_HPP

#include <GL/glew.h>
#include <algorithm>

class Color
{
public:
    GLfloat r;
    GLfloat g;
    GLfloat b;
    
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Cyan;
    static const Color Pink;

public:
    Color();
    Color(GLfloat r, GLfloat g, GLfloat b);
    Color Normalise() const;
};

#endif