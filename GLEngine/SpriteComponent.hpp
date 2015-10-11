#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Component.hpp"
#include "Texture.hpp"
#include "Color.hpp"
#include "ShaderProgram.hpp"

class SpriteComponent : public Component
{
private:
	ShaderProgram m_shaderProgram;
	GLuint m_vao;
	Texture* mp_texture;
	Color m_color;

public:
	SpriteComponent();
	~SpriteComponent();
	virtual void Start() override;
	virtual void Update() override;
	void InitRenderData();
	void SetTexture(Texture* p_texture);
	void SetColor(const Color& color);
	void SetShaderProgram(ShaderProgram& shaderProgram);
	const Texture* GetTexture() const;
	const Color& GetColor() const;
};

#endif