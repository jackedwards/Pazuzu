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
#include <memory>

// Forward declaring to avoid circular inclusion
class Component;

class GameObject
{
public:
	GameObject* mp_parent;
	std::vector<GameObject*> m_children;
	std::unordered_map<std::type_index, std::shared_ptr<Component> > m_components;
private:
	Transform m_transform;
	std::string m_name;
	std::string m_tag;
	GLboolean m_enabled;

public:
	GameObject(std::string name);
	GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation);
    template<class T> void AddComponent();
    template<class T> void RemoveComponent();
	template<class T> bool HasComponent();
    template<class T> std::shared_ptr<T> GetComponent();
    const glm::vec2& GetPosition() const;
    const glm::vec2& GetSize() const;
    const GLfloat& GetRotation() const;
    const std::string& GetName() const;
    const std::string& GetTag() const;
    const GLboolean& GetEnabled() const;
    void Move(const glm::vec2& position);
	void Move(const GLfloat& x, const GLfloat& y);
	void Scale(const glm::vec2& scale);
	void Scale(const GLfloat& x, const GLfloat& y);
	void Rotate(const GLfloat& rotation);
    void SetPosition(const glm::vec2& position);
    void SetPosition(const GLfloat& x, const GLfloat& y);
    void SetSize(const glm::vec2& size);
    void SetSize(const GLfloat& x, const GLfloat& y);
    void SetRotation(const GLfloat& rotation);
    void SetName(const std::string& name);
    void SetTag(const std::string& tag);
    void SetEnabled(const GLboolean& enabled);
};

#include "GameObject.tpp"

#endif