#ifndef PLAYERMOVE_HPP
#define PLAYERMOVE_HPP

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "Keyboard.hpp"

class PlayerMove : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_speed;
	GLboolean m_inverse;

public:
	PlayerMove();
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif