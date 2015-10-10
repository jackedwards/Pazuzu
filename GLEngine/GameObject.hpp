#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Transform.hpp"
#include "Component.hpp"
#include "SpriteComponent.hpp"

class GameObject
{
public:
	Transform m_transform;
	GameObject* mp_parent;
	std::vector<GameObject*> m_children;
private:
	std::unordered_map<std::type_index, ComponentPtr> m_components;

public:
	GameObject();
	GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation);
    template <class T> void AddComponent();
    template <class T> void RemoveComponent();
	template <class T> bool HasComponent();
    template <class T> std::shared_ptr<T> GetComponent();
};

#include "GameObject.tpp"

#endif