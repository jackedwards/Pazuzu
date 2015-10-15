#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
#include "GameObject.hpp"
#include "Collision.hpp"

class Component
{
public:
	GameObject* mp_gameObject;

public:
	virtual ~Component() { }
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void OnCollisionEnter(Collision collision) { }
};

#endif