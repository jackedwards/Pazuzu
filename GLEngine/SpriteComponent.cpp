#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
	
}

void SpriteComponent::Start()
{
	
}

void SpriteComponent::Update()
{
	
}

void SpriteComponent::SetTexture(Texture* p_texture)
{
	mp_texture = p_texture;
}

void SpriteComponent::SetColor(const Color& color)
{
	m_color = color;
}

const Texture* SpriteComponent::GetTexture() const
{
	return mp_texture;
}

const Color& SpriteComponent::GetColor() const
{
	return m_color;
}
