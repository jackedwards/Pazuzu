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
	Component(GameObject* gameObject) : mp_gameObject(gameObject) { }
	virtual ~Component() { }
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void OnCollisionEnter(Collision collision) { }
	virtual void OnCollisionStay(Collision collision) { }
	virtual void OnCollisionExit(Collision collision) { }
};

#endif