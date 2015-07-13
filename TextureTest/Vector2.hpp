#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <GL/glew.h>

template <typename T>
class Vector2
{
public:
    T x;
    T y;

public:
    Vector2() : x(0), y(0) {};
    Vector2(T X, T Y) : x(X), y(Y) {};
};

typedef Vector2<GLint> Vector2i;
typedef Vector2<GLuint> Vector2u;
typedef Vector2<GLfloat> Vector2f;

#endif
