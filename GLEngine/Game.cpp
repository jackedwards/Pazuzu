#include "Game.hpp"

Game::Game(GLuint width, GLuint height)
	: m_state(GAME_ACTIVE), m_keys(), m_width(width), m_height(height),
	  m_sprite1(glm::vec2(250, 250), glm::vec2(250, 250), 0.0f),
	  m_sprite2(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f),
	  m_player(glm::vec2(50, 50), glm::vec2(250, 250), 0.0f)
{

}

void Game::Init()
{
	m_player.AddComponent<SpriteComponent>();
	m_player.GetComponent<SpriteComponent>()->SetTexture(ResourceManager::GetTexture("awesomeface"));

	m_sprite1.SetTexture(ResourceManager::GetTexture("awesomeface"));
	m_sprite2.SetTexture(ResourceManager::GetTexture("bliss"));

	VertexShader vertShader("shaders/vertex-shader.glsl");
	FragmentShader fragShader("shaders/fragment-shader.glsl");
	ShaderProgram shaderProgram(vertShader, fragShader);

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), static_cast<GLfloat>(m_height), 0.0f, -1.0f, 1.0f);

	shaderProgram.Use();
	glUniform1i(shaderProgram.GetUniformLocation("image"), 0);
	glUniformMatrix4fv(shaderProgram.GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));

	mp_renderer = new SpriteRenderer(shaderProgram);
}

void Game::Update(GLfloat dt)
{
	
}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	mp_renderer->Draw(m_sprite2);
	//mp_renderer->Draw(m_sprite1);
	mp_renderer->Draw(m_player);
}