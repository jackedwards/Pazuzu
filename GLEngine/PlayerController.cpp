#include "PlayerController.hpp"

PlayerController::PlayerController(GameObject* gameObject) : Component(gameObject)
{
	
}

void PlayerController::Start()
{
	m_speed = 5.0f;
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::Update()
{
	if (Keyboard::IsKeyPressed(GLFW_KEY_W))
		m_velocity.y = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_S))
		m_velocity.y = m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_A))
		m_velocity.x = -m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_D))
		m_velocity.x = m_speed;
	if (Keyboard::IsKeyPressed(GLFW_KEY_SPACE))
	{
		std::shared_ptr<GameObject> bullet = LevelManager::GetCurrentLevel()->CreateObject("Bullet", glm::vec2(50, 50), glm::vec2(10, 10), 0.0f);
		bullet->AddComponent<Sprite>();
		bullet->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));
		bullet->AddComponent<BulletMove>();
	}

	mp_gameObject->Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::OnCollisionEnter(Collision collision)
{

}
