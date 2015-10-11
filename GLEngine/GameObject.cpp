#include "GameObject.hpp"

GameObject::GameObject() : mp_parent(nullptr) { }

//GameObject(std::string name) : mp_parent(nullptr), m_name(name) { }

GameObject::GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_transform(position, size, rotation) { }

/*GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_name(name), m_transform(position, size, rotation) { }*/