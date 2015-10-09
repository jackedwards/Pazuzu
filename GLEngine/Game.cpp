#include "Game.hpp"

Game::Game(GLuint width, GLuint height)
	: m_state(GAME_ACTIVE), m_keys(), m_width(width), m_height(height),
	  m_sprite1(glm::vec2(250, 250), glm::vec2(250, 250), 45.0f),
	  m_sprite2(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f)
{

}

void Game::Init()
{
	/*m_texture1.LoadFromFile("resources/awesomeface.bmp");
	m_sprite1.SetTexture(m_texture1);

	m_texture2.LoadFromFile("resources/bliss.bmp");
	m_sprite2.SetTexture(m_texture2);*/

	m_sprite1.SetTexture(ResourceManager::GetTexture("awesomeface"));
	m_sprite2.SetTexture(ResourceManager::GetTexture("bliss"));

	VertexShader vertShader("shaders/vertex-shader.glsl");
	FragmentShader fragShader("shaders/fragment-shader.glsl");
	ShaderProgram shaderProgram(vertShader, fragShader);

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->m_width), static_cast<GLfloat>(this->m_height), 0.0f, -1.0f, 1.0f);

	shaderProgram.Use();
	glUniform1i(shaderProgram.GetUniformLocation("image"), 0);
	glUniformMatrix4fv(shaderProgram.GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));

	mp_renderer = new SpriteRenderer(shaderProgram);
}

void Game::Update(GLfloat dt)
{
	GLfloat rotation = 5.0f * dt;
	GLfloat currentRot = m_sprite1.GetRotation();

	m_sprite1.SetRotation(currentRot + rotation);
}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	mp_renderer->Draw(m_sprite2);
	mp_renderer->Draw(m_sprite1);
}