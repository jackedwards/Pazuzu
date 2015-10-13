#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "GameObject.hpp"

class Component
{
public:
	GameObject* m_gameObject;

public:
	virtual ~Component() { }
	virtual void Start() = 0;
	virtual void Update() = 0;
};

#endif