#include "PlayerMove.hpp"

PlayerMove::PlayerMove(GameObject* gameObject) : Component(gameObject)
{
	m_colors[0] = Color::Black;
	m_colors[1] = Color::White;
	m_colors[2] = Color::Red;
	m_colors[3] = Color::Green;
	m_colors[4] = Color::Blue;
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
	if (collision.mp_gameObject->m_name == "Ball")
	{
		GLint index = Random::GetRandomNumber(0, 5);
		mp_gameObject->GetComponent<Sprite>()->SetColor(m_colors[index]);
	}
}
