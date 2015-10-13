#include "Transform.hpp"

Transform::Transform()
{
	
}

void Transform::Start()
{
	
}

void Transform::Update()
{
	
}

void Transform::Move(const glm::vec2& position)
{
	m_position += position;
}

void Transform::Move(const GLfloat& x, const GLfloat& y)
{
	m_position += glm::vec2(x, y);
}

void Transform::Scale(const glm::vec2& scale)
{
	m_size += scale;
}

void Transform::Scale(const GLfloat& x, const GLfloat& y)
{
	m_size += glm::vec2(x, y);
}

void Transform::Rotate(const GLfloat& rotation)
{
	m_rotation += rotation;
}

void Transform::SetPosition(const glm::vec2 position)
{
	m_position = position;
}

void Transform::SetPosition(const GLfloat x, const GLfloat y)
{
	m_position = glm::vec2(x, y);
}

void Transform::SetSize(const glm::vec2 size)
{
	m_size = size;
}

void Transform::SetSize(const GLfloat x, const GLfloat y)
{
	m_size = glm::vec2(x, y);
}

void Transform::SetRotation(const GLfloat rotation)
{
	m_rotation = rotation;
}

const glm::vec2& Transform::GetPosition() const
{
	return m_position;
	//return (mp_gameObject->mp_parent != nullptr) ? mp_parent->m_position + m_localPosition : m_position;
}

const glm::vec2& Transform::GetSize() const
{
	return m_size;
}

const GLfloat& Transform::GetRotation() const
{
	return m_rotation;
}

const glm::vec2& Transform::GetLocalPosition() const
{

}

const glm::vec2& Transform::GetLocalSize() const
{

}

const GLfloat& Transform::GetLocalRotation() const
{

}
