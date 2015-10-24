#include "PlayerController.hpp"

PlayerController::PlayerController(GameObject* gameObject) : Component(gameObject)
{
	
}

void PlayerController::Start()
{
	m_speed = 10.0f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::Update()
{
	if (Keyboard::IsKeyPressed(GLFW_KEY_A))
		m_velocity.x = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_D))
		m_velocity.x = m_speed;

	//if (!m_isGrounded)
		m_velocity.y += m_speed;

	mp_gameObject->m_transform.Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::OnCollisionEnter(Collision collision)
{
	//m_isGrounded = true;
	std::cout << "PlayerController: ENTER\n";
}

void PlayerController::OnCollisionStay(Collision collision)
{
	std::cout << "PlayerController: STAY\n";
}

void PlayerController::OnCollisionExit(Collision collision)
{
	std::cout << "PlayerController: EXIT\n";
}
