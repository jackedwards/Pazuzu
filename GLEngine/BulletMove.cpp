#include "BulletMove.hpp"

BulletMove::BulletMove(GameObject* gameObject) : Component(gameObject)
{
	
}

void BulletMove::Start()
{
	m_speed = 3.0f;
	m_velocity = glm::vec2(m_speed, m_speed);
}

void BulletMove::Update()
{
	mp_gameObject->Move(m_velocity);
}
