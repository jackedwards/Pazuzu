#include "PlayerController.hpp"

PlayerController::PlayerController(GameObject* gameObject) : Component(gameObject)
{
	
}

void PlayerController::Start()
{
	m_moveSpeed = 10.0f;
	m_fallSpeed = 0.0f;
	m_fallAcceleration = 0.2f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::Update()
{
	if (Keyboard::IsKeyPressed(GLFW_KEY_W))
		m_velocity.y = -m_moveSpeed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_S))
		m_velocity.y = m_moveSpeed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_A))
		m_velocity.x = -m_moveSpeed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_D))
		m_velocity.x = m_moveSpeed;

	if (!m_isGrounded)
	{
		m_fallSpeed += m_fallAcceleration;
		m_velocity.y += m_fallSpeed;
	}

	mp_gameObject->m_transform.Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::OnCollisionEnter(Collision collision)
{
	glm::vec2 position = mp_gameObject->m_transform.GetPosition();

	std::cout << "Current pos: " << position.x << ", " << position.y << '\n';
	std::cout << "Intersection: " << collision.m_intersection.x << ", " << collision.m_intersection.y << '\n';
	mp_gameObject->m_transform.Move(0, -collision.m_intersection.y);
	position = mp_gameObject->m_transform.GetPosition();
	std::cout << "After move pos: " << position.x << ", " << position.y << '\n';
	m_isGrounded = true;
	m_fallSpeed = 0.0f;
}

void PlayerController::OnCollisionStay(Collision collision)
{
	glm::vec2 position = mp_gameObject->m_transform.GetPosition();
	
	std::cout << "Current pos: " << position.x << ", " << position.y << '\n';
	std::cout << "Intersection: " << collision.m_intersection.x << ", " << collision.m_intersection.y << '\n';
	mp_gameObject->m_transform.Move(0, -collision.m_intersection.y);
	position = mp_gameObject->m_transform.GetPosition();
	std::cout << "After move pos: " << position.x << ", " << position.y << '\n';
}

void PlayerController::OnCollisionExit(Collision collision)
{
	m_isGrounded = false;
}
