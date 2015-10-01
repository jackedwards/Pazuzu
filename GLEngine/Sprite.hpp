#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "glm/glm.hpp"
#include "Texture.hpp"

class Sprite
{
private:
	Texture* mp_texture;
	glm::vec2 m_position;
	glm::vec2 m_size;
	GLfloat m_rotation;
	Color m_color;

public:
	Sprite();
	Sprite(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	Sprite(glm::vec2 position, glm::vec2 size, GLfloat rotation, Color color);
	void SetTexture(Texture& texture);
	void SetPosition(glm::vec2 position);
	void SetSize(glm::vec2 size);
	void SetRotation(GLfloat rotation);
	void SetColor(Color color);
	const Texture* GetTexture() const;
	glm::vec2 GetPosition() const;
	glm::vec2 GetSize() const;
	GLfloat GetRotation() const;
	Color GetColor() const;
};

#endif