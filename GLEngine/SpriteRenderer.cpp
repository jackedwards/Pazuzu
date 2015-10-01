#include "SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(ShaderProgram& shaderProgram)
{
	this->m_shaderProgram = shaderProgram;
	this->InitRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &this->m_vao);
}

void SpriteRenderer::Draw(Sprite sprite)
{
	glm::vec2 position = sprite.GetPosition();
	glm::vec2 size = sprite.GetSize();
	GLfloat rotation = sprite.GetRotation();
	Color color = sprite.GetColor();
	const Texture* texture = sprite.GetTexture();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));

	glUniformMatrix4fv(this->m_shaderProgram.GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform3f(this->m_shaderProgram.GetUniformLocation("spriteColor"), color.r, color.g, color.b);

	texture->Bind();

	glBindVertexArray(this->m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void SpriteRenderer::InitRenderData()
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