#include "Sprite.hpp"

Sprite::Sprite()
{
	
}

Sprite::Sprite(glm::vec2 position, glm::vec2 size, GLfloat rotation)
{
	m_position = position;
	m_size = size;
	m_rotation = rotation;
	m_color = Color();
}

Sprite::Sprite(glm::vec2 position, glm::vec2 size, GLfloat rotation, Color color)
{
	m_position = position;
	m_size = size;
	m_rotation = rotation;
	m_color = color;
}

void Sprite::SetTexture(Texture* p_texture)
{
	mp_texture = p_texture;
}

void Sprite::SetPosition(glm::vec2 position)
{
	m_position = position;
}

void Sprite::SetSize(glm::vec2 size)
{
	m_size = size;
}

void Sprite::SetRotation(GLfloat rotation)
{
	m_rotation = rotation;
}

void Sprite::SetColor(Color color)
{
	m_color = color;
}

const Texture* Sprite::GetTexture() const
{
	return mp_texture;
}

glm::vec2 Sprite::GetPosition() const
{
	return m_position;
}

glm::vec2 Sprite::GetSize() const
{
	return m_size;
}

GLfloat Sprite::GetRotation() const
{
	return m_rotation;
}

Color Sprite::GetColor() const
{
	return m_color;
}