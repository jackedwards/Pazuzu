#ifndef PLAYERMOVECOMPONENT_HPP
#define PLAYERMOVECOMPONENT_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "Keyboard.hpp"

class PlayerMoveComponent : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_speed;

public:
	PlayerMoveComponent();
	virtual void Start() override;
	virtual void Update() override;
};

#endif