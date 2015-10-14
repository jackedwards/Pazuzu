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

	m_gameObject->m_transform.Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}


void PlayerMove::OnCollisionEnter()
{
	std::cout << "PlayerMove: Colliding!\n";
}