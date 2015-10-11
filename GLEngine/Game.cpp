#include "Game.hpp"

Game::Game(GLuint width, GLuint height)
	: m_state(GAME_ACTIVE), m_keys(), m_width(width), m_height(height),
	  m_player(glm::vec2(50, 50), glm::vec2(250, 250), 0.0f),
	  m_background(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f)
{

}

void Game::Init()
{
	m_player.AddComponent<SpriteComponent>();
	m_background.AddComponent<SpriteComponent>();
	m_player.GetComponent<SpriteComponent>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	m_background.GetComponent<SpriteComponent>()->SetTexture(ResourceManager::GetTexture("bliss"));

	VertexShader vertShader("shaders/vertex-shader.glsl");
	FragmentShader fragShader("shaders/fragment-shader.glsl");
	ShaderProgram shaderProgram(vertShader, fragShader);

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), static_cast<GLfloat>(m_height), 0.0f, -1.0f, 1.0f);

	shaderProgram.Use();
	glUniform1i(shaderProgram.GetUniformLocation("image"), 0);
	glUniformMatrix4fv(shaderProgram.GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));

	mp_renderer = new SpriteRenderer(shaderProgram);
	std::shared_ptr<SpriteComponent> playerSpriteComp = m_player.GetComponent<SpriteComponent>();
	std::shared_ptr<SpriteComponent> backgroundSpriteComp = m_background.GetComponent<SpriteComponent>();

	playerSpriteComp->SetShaderProgram(shaderProgram);
	backgroundSpriteComp->SetShaderProgram(shaderProgram);
	playerSpriteComp->Start();
	backgroundSpriteComp->Start();
}

void Game::Update(GLfloat dt)
{
	
}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	//mp_renderer->Draw(m_background);
	//mp_renderer->Draw(m_player);
	m_background.GetComponent<SpriteComponent>()->Update();
	m_player.GetComponent<SpriteComponent>()->Update();
}