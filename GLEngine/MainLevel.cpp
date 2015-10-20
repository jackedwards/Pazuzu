#include "MainLevel.hpp"

MainLevel::MainLevel() { }

void MainLevel::Init()
{
	CreateObject("Background", glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	CreateObject("Player", glm::vec2(0, 0), glm::vec2(50, 50), 0.0f);
	CreateObject("Ground", glm::vec2(0, 500), glm::vec2(800, 20), 0.0f);

	std::shared_ptr<GameObject> background = GetObject("Background");
	background->AddComponent<Sprite>();
	background->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));

	std::shared_ptr<GameObject> player = GetObject("Player");
	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("awesomeface"));
	player->AddComponent<RectangleCollider>();
	player->AddComponent<PlayerController>();

	std::shared_ptr<GameObject> ground = GetObject("Ground");
	ground->AddComponent<Sprite>();
	ground->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));
	ground->AddComponent<RectangleCollider>();
}