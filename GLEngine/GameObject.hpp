#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Transform.hpp"

// Forward declaring to avoid circular inclusion
class Component;

class GameObject
{
public:
	GameObject* mp_parent;
	std::vector<GameObject*> m_children;
	std::string m_name;
	Transform m_transform;
	glm::vec2 m_velocity;
private:
	std::unordered_map<std::type_index, std::shared_ptr<Component> > m_components;

public:
	GameObject();
	GameObject(std::string name);
	GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation);
    template<class T> void AddComponent();
    template<class T> void RemoveComponent();
	template<class T> bool HasComponent();
    template<class T> std::shared_ptr<T> GetComponent();
};

#include "GameObject.tpp"

#endif