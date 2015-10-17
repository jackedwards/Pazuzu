#ifndef BALLMOVE_HPP
#define BALLMOVE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"

class BallMove : public Component
{
public:
	const GLfloat m_speed = 10.0f;
	glm::vec2 m_velocity;

public:
	BallMove(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif