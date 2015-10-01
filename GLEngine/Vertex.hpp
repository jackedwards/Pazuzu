#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Color.hpp"

class Vertex
{
public:
    glm::vec3 position;
    Color color;
    glm::vec2 texCoords;

public:
    Vertex();
    Vertex(glm::vec3 Position, Color Color, glm::vec2 TexCoords);
    Vertex(glm::vec3 Position, Color Color);
    Vertex(glm::vec3 Position, glm::vec2 TexCoords);
};

#endif
