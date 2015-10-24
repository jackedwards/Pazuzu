#include "TestLevel.hpp"

TestLevel::TestLevel(std::string name) : Level(name) { }

void TestLevel::Init()
{
	CreateObject("Background", glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	CreateObject("Player", glm::vec2(0, 0), glm::vec2(50, 50), 0.0f);

	std::shared_ptr<GameObject> background = GetObject("Background");
	background->AddComponent<Sprite>();
	background->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("awesomeface"));

	std::shared_ptr<GameObject> player = GetObject("Player");
	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->SetTexture(Resources::GetTexture("bliss"));
	player->AddComponent<RectangleCollider>();
	player->AddComponent<PlayerController>();
}
