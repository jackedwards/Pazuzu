#include "Vertex.hpp"

Vertex::Vertex()
{
    
}

Vertex::Vertex(Vector2f Position, Color Color, Vector2f TexCoords)
{
    position = Position;
    color = Color;
    texCoords = TexCoords;
}

Vertex::Vertex(Vector2f Position, Vector2f TexCoords)
{
    position = Position;
    color = Color();
    texCoords = TexCoords;
}