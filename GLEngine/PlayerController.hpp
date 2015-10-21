#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include <iostream>
#include "Component.hpp"
#include "Keyboard.hpp"

class PlayerController : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_moveSpeed;
	GLfloat m_fallSpeed;
	GLfloat m_fallAcceleration;
	GLboolean m_isGrounded = false;

public:
	PlayerController(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
	virtual void OnCollisionStay(Collision collision) override;
	virtual void OnCollisionExit(Collision collision) override;
};

#endif
