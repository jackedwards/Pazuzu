#ifndef BULLETMOVE_HPP
#define BULLETMOVE_HPP

#include "Component.hpp"

class BulletMove : public Component
{
private:
	GLfloat m_speed;
	glm::vec2 m_velocity;

public:
	BulletMove(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
};

#endif
