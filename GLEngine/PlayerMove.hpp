#ifndef PLAYERMOVE_HPP
#define PLAYERMOVE_HPP

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "Keyboard.hpp"
#include "Sprite.hpp"
#include "Random.hpp"

class PlayerMove : public Component
{
private:
	glm::vec2 m_velocity;
	GLfloat m_speed;
	Color m_colors[5];

public:
	PlayerMove(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif