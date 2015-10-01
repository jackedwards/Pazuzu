#ifndef PLANE_HPP
#define PLANE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Vertex.hpp"
#include "Color.hpp"
#include "Texture.hpp"

class Plane
{
private:
    Vertex vertices[4];

public:
	Plane();
    Plane(glm::vec2 position, glm::vec2 size);
	Plane(glm::vec2 position, glm::vec2 size, Color color);
	Plane(glm::vec2 position, glm::vec2 size, Texture texture);
};

#endif
