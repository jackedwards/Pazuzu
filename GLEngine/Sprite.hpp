#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Component.hpp"
#include "Texture.hpp"
#include "Color.hpp"
#include "ShaderProgram.hpp"
#include "Resources.hpp"

class Sprite : public Component
{
private:
	Texture* mp_texture;
	Color m_color;
	std::shared_ptr<ShaderProgram> mp_shader;

public:
	Sprite(GameObject* gameObject);
	virtual void Start() override;
	virtual void Update() override;
	void SetTexture(Texture* p_texture);
	void SetColor(const Color& color);
	void SetShader(const std::shared_ptr<ShaderProgram> shader);
	const Texture* GetTexture() const;
	const Color& GetColor() const;
	const std::shared_ptr<ShaderProgram>& GetShader() const;
};

#endif