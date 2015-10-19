#include "Game.hpp"

Game::Game(GLuint width, GLuint height) : m_width(width), m_height(height)
{
	m_levels.push_back(std::make_shared<MainLevel>());
}

void Game::Init()
{
	m_levels[0]->Init();

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), static_cast<GLfloat>(m_height), 0.0f, -1.0f, 1.0f);

	glUniformMatrix4fv(Resources::GetShader("default")->Use().GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(Resources::GetShader("red")->Use().GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));

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
