#include "Level.hpp"

void Level::Update(GLfloat dt)
{
	for (auto& gameObject : m_gameObjects)
		for (auto& kv : gameObject->m_components)
			if (gameObject->m_enabled)
				kv.second->Update();

	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		for (int j = 0; j < m_gameObjects.size(); ++j)
		{
			if (m_gameObjects[i]->m_enabled && m_gameObjects[j]->m_enabled)
				if (m_gameObjects[i] != m_gameObjects[j])
					CheckCollisions(m_gameObjects[i], m_gameObjects[j]);
		}
	}
}

void Level::Render(SpriteRenderer* renderer)
{
	for (auto& gameObject : m_gameObjects)
		if (gameObject->m_enabled)
			if (gameObject->HasComponent<Sprite>())
				renderer->Draw(gameObject);
}

void Level::CheckCollisions(std::shared_ptr<GameObject>& objectA, std::shared_ptr<GameObject>& objectB)
{
	if (objectA->HasComponent<RectangleCollider>() && objectB->HasComponent<RectangleCollider>())
	{
		std::shared_ptr<RectangleCollider> colliderA = objectA->GetComponent<RectangleCollider>();
		std::shared_ptr<RectangleCollider> colliderB = objectB->GetComponent<RectangleCollider>();

		if (colliderA->CollidingWith(colliderB))
		{
			if (!colliderA->m_colliding)
			{
				for (auto& kv : objectA->m_components)
					kv.second->OnCollisionEnter(colliderB->m_collision);
				colliderA->m_colliding = true;
				return;
			}

			if (colliderA->m_colliding)
			{
				for (auto& kv : objectA->m_components)
					kv.second->OnCollisionStay(colliderB->m_collision);
				return;
			}
		}
		else
		{
			if (colliderA->m_colliding)
			{
				for (auto& kv : objectA->m_components)
					kv.second->OnCollisionExit(colliderB->m_collision);
				colliderA->m_colliding = false;
				return;
			}
		}
	}
}

void Level::CreateObject()
{
	m_gameObjects.push_back(std::make_shared<GameObject>("GameObject"));
}

void Level::CreateObject(std::string name)
{
	m_gameObjects.push_back(std::make_shared<GameObject>(name));
}

void Level::CreateObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	m_gameObjects.push_back(std::make_shared<GameObject>("GameObject", position, size, rotation));
}

void Level::CreateObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	m_gameObjects.push_back(std::make_shared<GameObject>(name, position, size, rotation));
}

const std::shared_ptr<GameObject> Level::GetObject(const std::string name) const
{
	for (auto& gameObject : m_gameObjects)
		if (gameObject->m_name == name)
			return gameObject;

	return nullptr;
}
