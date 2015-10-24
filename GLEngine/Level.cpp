#include "Level.hpp"

Level::Level(std::string name) : m_name(name) { }

void Level::Update(GLfloat dt)
{
	for (auto& gameObject : m_gameObjects)
	{
		for (auto& kv : gameObject->m_components)
		{
			if (gameObject->GetEnabled())
			{
				kv.second->Update();
			}
		}
	}

	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		for (int j = 0; j < m_gameObjects.size(); ++j)
		{
			if (m_gameObjects[i]->GetEnabled() && m_gameObjects[j]->GetEnabled())
				if (m_gameObjects[i] != m_gameObjects[j])
					CheckCollisions(m_gameObjects[i], m_gameObjects[j]);
		}
	}

	AddFromQueue();	
}

void Level::Render(SpriteRenderer* renderer)
{
	for (auto& gameObject : m_gameObjects)
		if (gameObject->GetEnabled())
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

std::shared_ptr<GameObject> Level::CreateObject()
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>("GameObject");
	m_gameObjectQueue.push_back(gameObject);

	return gameObject;
}

std::shared_ptr<GameObject> Level::CreateObject(std::string name)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(name);
	m_gameObjectQueue.push_back(gameObject);

	return gameObject;
}

std::shared_ptr<GameObject> Level::CreateObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>("GameObject", position, size, rotation);
	m_gameObjectQueue.push_back(gameObject);

	return gameObject;
}

std::shared_ptr<GameObject> Level::CreateObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(name, position, size, rotation);
	m_gameObjectQueue.push_back(gameObject);

	return gameObject;
}

const std::shared_ptr<GameObject> Level::GetObject(const std::string& name) const
{
	for (auto& gameObject : m_gameObjects)
		if (gameObject->GetName() == name)
			return gameObject;

	for (auto& gameObject : m_gameObjectQueue)
		if (gameObject->GetName() == name)
			return gameObject;

	std::cout << "No object found with the name '" << name <<  "'.\n";
	return nullptr;
}

const std::vector<std::shared_ptr<GameObject> > Level::GetObjectsWithTag(const std::string& tag) const
{
	std::vector<std::shared_ptr<GameObject> > gameObjects;
	for (auto& gameObject : m_gameObjects)
		if (gameObject->GetTag() == tag)
			gameObjects.push_back(gameObject);

	for (auto& gameObject : m_gameObjectQueue)
		if (gameObject->GetTag() == tag)
			gameObjects.push_back(gameObject);

	if (gameObjects.size() == 0)
		std::cout << "No object found with the tag '" << tag <<  "'.\n";

	return gameObjects;
}

const std::string& Level::GetName() const
{
	return m_name;
}

void Level::AddFromQueue()
{
	m_gameObjects.insert(m_gameObjects.end(), m_gameObjectQueue.begin(), m_gameObjectQueue.end());
	m_gameObjectQueue.clear();
}
