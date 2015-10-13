#ifndef PLAYERMOVE_HPP
#define PLAYERMOVE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "Keyboard.hpp"
#include "Transform.hpp"

class PlayerMove : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_speed;

public:
	PlayerMove();
	virtual void Start() override;
	virtual void Update() override;
};

#endif