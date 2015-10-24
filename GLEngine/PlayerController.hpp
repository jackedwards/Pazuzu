#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include <iostream>
#include "Component.hpp"
#include "Keyboard.hpp"
#include "LevelManager.hpp"
#include "BulletMove.hpp"

class PlayerController : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_speed;

public:
	PlayerController(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif
