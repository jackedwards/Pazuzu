#ifndef RECTANGLECOLLIDER_HPP
#define RECTANGLECOLLIDER_HPP

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "Transform.hpp"

class RectangleCollider : public Component
{
private:
	glm::vec2 m_position;
	glm::vec2 m_size;

public:
	RectangleCollider();
	virtual void Start() override;
	virtual void Update() override;
	GLboolean CollidingWith(std::shared_ptr<RectangleCollider>& other);
};

#endif