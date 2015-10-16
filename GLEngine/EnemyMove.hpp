#ifndef ENEMYMOVE_HPP
#define ENEMYMOVE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"

class EnemyMove : public Component
{
public:
	const GLfloat m_speed = 8.0f;
	glm::vec2 m_velocity;

public:
	EnemyMove(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif