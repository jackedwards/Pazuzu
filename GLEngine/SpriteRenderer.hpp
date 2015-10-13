#ifndef SPRITERENDERER_HPP
#define SPRITERENDERER_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ErrorLogger.hpp"
#include "ShaderProgram.hpp"
#include "Texture.hpp"
#include "Color.hpp"
#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"

class SpriteRenderer
{
private:
	ShaderProgram m_shaderProgram;
	GLuint m_vao;

public:
	SpriteRenderer(ShaderProgram& shaderProgram);
	~SpriteRenderer();

public:
	void Draw(std::shared_ptr<GameObject>& gameObject);
private:
	void InitRenderData();
};

#endif