#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
	
}

SpriteComponent::~SpriteComponent()
{
	glDeleteVertexArrays(1, &m_vao);
}

void SpriteComponent::Start()
{
	InitRenderData();
}

void SpriteComponent::Update()
{
	glm::vec2 position = m_gameObject->m_transform.GetPosition();
	glm::vec2 size = m_gameObject->m_transform.GetSize();
	GLfloat rotation = m_gameObject->m_transform.GetRotation();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));

	glUniformMatrix4fv(m_shaderProgram.GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform3f(m_shaderProgram.GetUniformLocation("spriteColor"), m_color.r, m_color.g, m_color.b);

	mp_texture->Bind();

	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void SpriteComponent::InitRenderData()
{
	GLuint vbo;
	GLfloat vertices[] =
	{
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &this->m_vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(this->m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteComponent::SetTexture(Texture* p_texture)
{
	mp_texture = p_texture;
}

void SpriteComponent::SetColor(const Color& color)
{
	m_color = color;
}

void SpriteComponent::SetShaderProgram(ShaderProgram& shaderProgram)
{
	m_shaderProgram = shaderProgram;
}

const Texture* SpriteComponent::GetTexture() const
{
	return mp_texture;
}

const Color& SpriteComponent::GetColor() const
{
	return m_color;
}
