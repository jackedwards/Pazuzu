#include "GameObject.hpp"

GameObject::GameObject() : mp_parent(nullptr) { }

GameObject::GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: m_transform(position, size, rotation) { }