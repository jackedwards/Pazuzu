#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/glew.h>
#include "Vector2.hpp"
#include "Color.hpp"

class Vertex
{
public:
    Vector2f position;
    Color color;
    Vector2f texCoords;

public:
    Vertex();
    Vertex(Vector2f Position, Color Color, Vector2f TexCoords);
    Vertex(Vector2f Position, Color Color);
    Vertex(Vector2f Position, Vector2f TexCoords);
};

#endif
