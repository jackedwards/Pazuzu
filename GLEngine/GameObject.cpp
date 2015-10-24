#include "GameObject.hpp"

GameObject::GameObject(std::string name) : mp_parent(nullptr), m_name(name), m_enabled(true) { }

GameObject::GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_transform(position, size, rotation), m_enabled(true) { }

GameObject::GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_name(name), m_transform(position, size, rotation), m_enabled(true) { }
