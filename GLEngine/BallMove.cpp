#include "BallMove.hpp"

BallMove::BallMove(GameObject* gameObject) : Component(gameObject)
{
	
}

void BallMove::Start()
{
	m_velocity = glm::vec2(m_speed, m_speed);
}

void BallMove::Update()
{
	mp_gameObject->m_transform.Move(m_velocity);
	glm::vec2 position = mp_gameObject->m_transform.GetPosition();
	glm::vec2 size = mp_gameObject->m_transform.GetSize();

	if (position.x + size.x >= 800 || position.x <= 0)
		m_velocity.x = -m_velocity.x;
	if (position.y <= 0)
		m_velocity.y = -m_velocity.y;
	if (position.y >= 600)
		mp_gameObject->m_transform.SetPosition(position.x, 300);
}

void BallMove::OnCollisionEnter(Collision collision)
{
	if (collision.mp_gameObject->m_name == "Player")
		m_velocity.y = -m_velocity.y;

	if (collision.mp_gameObject->m_name == "Block")
	{
		m_velocity.y = -m_velocity.y;
		collision.mp_gameObject->m_enabled = false;
	}
}
