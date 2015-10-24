#include "PlayerController.hpp"

PlayerController::PlayerController(GameObject* gameObject) : Component(gameObject)
{
	
}

void PlayerController::Start()
{
	m_speed = 5.0f;
	m_velocity = glm::vec2(0, 0);

	//for (int i = 0; i < 1000; ++i)
	//	LevelManager::GetCurrentLevel()->CreateObject("Bullet", glm::vec2(50, 50), glm::vec2(10, 10), 0.0f);
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
		LevelManager::GetCurrentLevel()->CreateObject("Bullet", glm::vec2(50, 50), glm::vec2(10, 10), 0.0f);
		std::shared_ptr<GameObject> bullet = LevelManager::GetCurrentLevel()->GetObject("Bullet");
		bullet->AddComponent<Sprite>();
		bullet->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));
		bullet->AddComponent<BulletMove>();
		std::cout << "Created bullet!\n";
	}

	mp_gameObject->m_transform.Move(m_velocity);
	m_velocity = glm::vec2(0, 0);
}

void PlayerController::OnCollisionEnter(Collision collision)
{

}
