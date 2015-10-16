#include "EnemyMove.hpp"

EnemyMove::EnemyMove(GameObject* gameObject) : Component(gameObject)
{
	
}

void EnemyMove::Start()
{
	m_velocity = glm::vec2(m_speed, m_speed);
}

void EnemyMove::Update()
{
	mp_gameObject->m_transform.Move(m_velocity);
	glm::vec2 position = mp_gameObject->m_transform.GetPosition();
	glm::vec2 size = mp_gameObject->m_transform.GetSize();

	if (position.x + size.x >= 800 || position.x <= 0)
		m_velocity.x = -m_velocity.x;
	if (position.y + size.y >= 600 || position.y <= 0)
		m_velocity.y = -m_velocity.y;
}

void EnemyMove::OnCollisionEnter(Collision collision)
{
	if (collision.mp_gameObject->m_name == "Player")
	{
		m_velocity = -m_velocity;
	}
}
