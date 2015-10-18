#include "MainLevel.hpp"

MainLevel::MainLevel() { }

void MainLevel::Init()
{
	CreateObject("Background", glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	CreateObject("Player", glm::vec2(300, 565), glm::vec2(200, 25), 0.0f);
	CreateObject("Ball", glm::vec2(300, 300), glm::vec2(25, 25), 0.0f);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			CreateObject("Block", glm::vec2(i * 100, j * 25), glm::vec2(100, 25), 0.0f);
		}
	}

	for (auto& gameObject : m_gameObjects)
	{
		if (gameObject->m_name == "Block")
		{
			gameObject->AddComponent<Sprite>();
			gameObject->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));
			gameObject->AddComponent<RectangleCollider>();
		}
	}

	std::shared_ptr<GameObject> background = GetObject("Background");
	std::shared_ptr<GameObject> player = GetObject("Player");
	std::shared_ptr<GameObject> ball = GetObject("Ball");

	background->AddComponent<Sprite>();
	background->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));

	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("awesomeface"));
	player->AddComponent<RectangleCollider>();
	player->AddComponent<PlayerMove>();

	ball->AddComponent<Sprite>();
	ball->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("awesomeface"));
	ball->AddComponent<RectangleCollider>();
	ball->AddComponent<BallMove>();
}