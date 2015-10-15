#include "PlayerMove.hpp"

PlayerMove::PlayerMove()
{
	
}

void PlayerMove::Start()
{
	m_speed = 5.0f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerMove::Update()
{
	if (Keyboard::IsKeyPressed(GLFW_KEY_W))
		m_velocity.y = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_S))
		m_velocity.y = m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_A))
		m_velocity.x = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_D))
		m_velocity.x = m_speed;

	mp_gameObject->m_transform.Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}


void PlayerMove::OnCollisionEnter(Collision collision)
{
	if (!m_inverse)
	{
		collision.mp_gameObject->m_transform.Scale(-1.0f, -1.0f);
		glm::vec2 size = collision.mp_gameObject->m_transform.GetSize();

		if (size.x <= 5 && size.y <= 5)
			m_inverse = true;
	}
	else
	{
		collision.mp_gameObject->m_transform.Scale(1.0f, 1.0f);
		glm::vec2 size = collision.mp_gameObject->m_transform.GetSize();

		if (size.x >= 150 && size.y <= 150)
			m_inverse = false;
	}
}