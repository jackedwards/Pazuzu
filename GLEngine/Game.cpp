#include "Game.hpp"

Game::Game(GLuint width, GLuint height) : m_width(width), m_height(height)
{
	m_levels.push_back(std::make_shared<MainLevel>());
}

void Game::Init()
{
	m_levels[0]->Init();

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), static_cast<GLfloat>(m_height), 0.0f, -1.0f, 1.0f);

	Resources::GetShader("default")->Use().SetMatrix4("projection", projection);
	Resources::GetShader("red")->Use().SetMatrix4("projection", projection);

	mp_renderer = new SpriteRenderer();
}

void Game::Update(GLfloat dt)
{
	m_levels[0]->Update(dt);
}

void Game::Render()
{
	m_levels[0]->Render(mp_renderer);
}
