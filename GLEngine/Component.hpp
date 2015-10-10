#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

class Component
{
public:
	virtual ~Component() { }
	virtual void Start() = 0;
	virtual void Update() = 0;
};

typedef std::shared_ptr<Component> ComponentPtr;

#endif