#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "GameObject.hpp"

class Collision
{
public:
	GameObject* mp_gameObject;
	glm::vec2 m_intersection;

public:
	Collision(GameObject* gameObject);
};

#endif