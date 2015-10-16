#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.hpp"

class Rigidbody : public Component
{
public:
	glm::vec2 m_velocity;
	GLfloat m_gravity;

public:
	Rigidbody(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collision collision) override;
};

#endif