#include "MainLevel.hpp"

MainLevel::MainLevel() { }

void MainLevel::Init()
{
	CreateObject("Background", glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	CreateObject("Player", glm::vec2(0, 0), glm::vec2(100, 100), 0.0f);
	CreateObject("Enemy", glm::vec2(300, 0), glm::vec2(100, 100), 0.0f);

	std::shared_ptr<GameObject> background = GetObject("Background");
	std::shared_ptr<GameObject> player = GetObject("Player");
	std::shared_ptr<GameObject> enemy = GetObject("Enemy");

	background->AddComponent<Sprite>();
	background->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("bliss"));

	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	player->AddComponent<RectangleCollider>();
	player->AddComponent<PlayerMove>();

	enemy->AddComponent<Sprite>();
	enemy->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	enemy->AddComponent<RectangleCollider>();
}
