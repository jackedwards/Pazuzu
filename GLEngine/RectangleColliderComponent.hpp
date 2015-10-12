#ifndef RECTANGLECOLLIDERCOMPONENT_HPP
#define RECTANGLECOLLIDERCOMPONENT_HPP

#include "Component.hpp"

class RectangleColliderComponent : public Component
{
private:
	

public:
	RectangleColliderComponent();
	virtual void Start() override;
	virtual void Update() override;
};

#endif