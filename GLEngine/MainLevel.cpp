#include "MainLevel.hpp"

MainLevel::MainLevel() { }

void MainLevel::Init()
{
	CreateObject("Background", glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	CreateObject("Player", glm::vec2(300, 565), glm::vec2(200, 25), 0.0f);
	CreateObject("Ball", glm::vec2(300, 0), glm::vec2(25, 25), 0.0f);

	std::shared_ptr<GameObject> background = GetObject("Background");
	std::shared_ptr<GameObject> player = GetObject("Player");
	std::shared_ptr<GameObject> ball = GetObject("Ball");

	background->AddComponent<Sprite>();
	background->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("bliss"));

	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	player->AddComponent<RectangleCollider>();
	player->AddComponent<PlayerMove>();

	ball->AddComponent<Sprite>();
	ball->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	ball->AddComponent<RectangleCollider>();
}