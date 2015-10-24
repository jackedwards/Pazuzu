#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "GameObject.hpp"

class Collision
{
public:
	GameObject* mp_gameObject;

public:
	Collision(GameObject* gameObject);
};

#endif