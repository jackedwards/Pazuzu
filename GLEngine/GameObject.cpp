#include "GameObject.hpp"

GameObject::GameObject(std::string name) : mp_parent(nullptr), m_name(name), m_enabled(true) { }

GameObject::GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_transform(position, size, rotation), m_enabled(true) { }

GameObject::GameObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation)
	: mp_parent(nullptr), m_name(name), m_transform(position, size, rotation), m_enabled(true) { }

const glm::vec2& GameObject::GetPosition() const
{
	return m_transform.GetPosition();
}

const glm::vec2& GameObject::GetSize() const
{
	return m_transform.GetSize();
}

const GLfloat& GameObject::GetRotation() const
{
	return m_transform.GetRotation();
}

const std::string& GameObject::GetName() const
{
	return m_name;
}

const std::string& GameObject::GetTag() const
{
	return m_tag;
}

const GLboolean& GameObject::GetEnabled() const
{
	return m_enabled;
}

void GameObject::Move(const glm::vec2& position)
{
	m_transform.Move(position);
}

void GameObject::Move(const GLfloat& x, const GLfloat& y)
{
	m_transform.Move(x, y);
}

void GameObject::Scale(const glm::vec2& scale)
{
	m_transform.Scale(scale);
}

void GameObject::Scale(const GLfloat& x, const GLfloat& y)
{
	m_transform.Scale(x, y);
}

void GameObject::Rotate(const GLfloat& rotation)
{
	m_transform.Rotate(rotation);
}

void GameObject::SetPosition(const glm::vec2& position)
{
	m_transform.SetPosition(position);
}

void GameObject::SetPosition(const GLfloat& x, const GLfloat& y)
{
	m_transform.SetPosition(x, y);
}

void GameObject::SetSize(const glm::vec2& size)
{
	m_transform.SetSize(size);
}

void GameObject::SetSize(const GLfloat& x, const GLfloat& y)
{
	m_transform.SetSize(x, y);
}

void GameObject::SetRotation(const GLfloat& rotation)
{
	m_transform.SetRotation(rotation);
}

void GameObject::SetName(const std::string& name)
{
	m_name = name;
}

void GameObject::SetTag(const std::string& tag)
{
	m_tag = tag;
}

void GameObject::SetEnabled(const GLboolean& enabled)
{

}
