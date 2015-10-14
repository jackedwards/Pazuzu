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

void SpriteRenderer::Draw(std::shared_ptr<GameObject>& gameObject)
{
	std::shared_ptr<Sprite> spriteComp = gameObject->GetComponent<Sprite>();
	glm::vec2 position = gameObject->m_transform.GetPosition();
	glm::vec2 size = gameObject->m_transform.GetSize();
	GLfloat rotation = gameObject->m_transform.GetRotation();
	Color color = spriteComp->GetColor();
	const Texture* texture = spriteComp->GetTexture();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));

	glUniformMatrix4fv(m_shaderProgram.GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform3f(m_shaderProgram.GetUniformLocation("spriteColor"), color.r, color.g, color.b);

	texture->Bind();

	glBindVertexArray(m_vao);
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