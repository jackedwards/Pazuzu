#include "Sprite.hpp"

Sprite::Sprite(GameObject* gameObject) : Component(gameObject)
{
	
}

void Sprite::Start()
{
	mp_shader = Resources::GetShader("default");
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

void Sprite::SetShader(const std::shared_ptr<ShaderProgram> shader)
{
	mp_shader = shader;
}

const Texture* Sprite::GetTexture() const
{
	return mp_texture;
}

const Color& Sprite::GetColor() const
{
	return m_color;
}

const std::shared_ptr<ShaderProgram>& Sprite::GetShader() const
{
	return mp_shader;
}
