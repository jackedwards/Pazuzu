#include "GameObject.hpp"

GameObject::GameObject() : mp_parent(nullptr) { }

GameObject::GameObject(std::string name) : mp_parent(nullptr), m_name(name) { }

GameObject::GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr) { }//, m_transform(position, size, rotation) { }

GameObject::GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_name(name) { }//, m_transform(position, size, rotation) { }

void GameObject::AddChild()
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>();
	gameObject->mp_parent = this;
	m_children.push_back(gameObject);
}

void GameObject::AddChild(std::string name)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(name);
	gameObject->mp_parent = this;
	m_children.push_back(gameObject);
}

void GameObject::AddChild(glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(position, size, rotation);
	gameObject->mp_parent = this;
	m_children.push_back(gameObject);
}

void GameObject::AddChild(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(name, position, size, rotation);
	gameObject->mp_parent = this;
	m_children.push_back(gameObject);
}