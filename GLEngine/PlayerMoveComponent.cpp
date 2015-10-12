#include "PlayerMoveComponent.hpp"

PlayerMoveComponent::PlayerMoveComponent()
{
	
}

void PlayerMoveComponent::Start()
{
	m_speed = 5.0f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerMoveComponent::Update()
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