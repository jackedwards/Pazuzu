#include "PlayerMove.hpp"

PlayerMove::PlayerMove(GameObject* gameObject) : Component(gameObject)
{
	
}

void PlayerMove::Start()
{
	m_speed = 10.0f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerMove::Update()
{
	glm::vec2 position = mp_gameObject->m_transform.GetPosition();
	glm::vec2 size = mp_gameObject->m_transform.GetSize();

	if (Keyboard::IsKeyPressed(GLFW_KEY_A))
		m_velocity.x = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_D))
		m_velocity.x = m_speed;

	if (position.x + m_velocity.x >= 0 &&
		(position.x + size.x) + m_velocity.x <= 800)
		mp_gameObject->m_transform.Move(m_velocity);

	m_velocity = glm::vec2(0, 0);
}


void PlayerMove::OnCollisionEnter(Collision collision)
{

}
