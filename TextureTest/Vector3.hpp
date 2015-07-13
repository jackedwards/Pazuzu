#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <GL/glew.h>

template <typename T>
class Vector3
{
public:
    T x;
    T y;
    T z;
    
public:
    Vector2() : x(0), y(0), z(0) {};
    Vector2(T X, T Y, T Z) : x(X), y(Y), z(Z) {};
};

typedef Vector3<GLint> Vector3i;
typedef Vector3<GLuint> Vector3u;
typedef Vector3<GLfloat> Vector3f;

#endif