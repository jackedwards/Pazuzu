#include "Sprite.hpp"

Sprite::Sprite(GameObject* gameObject) : Component(gameObject)
{
	
}

void Sprite::Start()
{
	mp_shaderProgram = Resources::GetShaderProgram("red");
}

void Sprite::Update()
{
	
}

void Sprite::SetTexture(Texture* p_texture)
{
	mp_texture = p_texture;
}

void Sprite::SetColor(const Color& color)
{
	m_color = color;
}

const Texture* Sprite::GetTexture() const
{
	return mp_texture;
}

const Color& Sprite::GetColor() const
{
	return m_color;
}
