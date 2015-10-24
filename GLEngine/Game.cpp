#include "Game.hpp"

Game::Game(GLuint width, GLuint height) : m_width(width), m_height(height)
{
	
}

void Game::Init()
{
	LevelManager::Init();
	LevelManager::SetCurrentLevel("MainLevel");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(m_width), static_cast<GLfloat>(m_height), 0.0f, -1.0f, 1.0f);

	Resources::GetShader("default")->Use().SetMatrix4("projection", projection);
	Resources::GetShader("red")->Use().SetMatrix4("projection", projection);

	mp_renderer = new SpriteRenderer();
}

void Game::Update(GLfloat dt)
{
	LevelManager::Update(dt);
}

void Game::Render()
{
	LevelManager::Render(mp_renderer);
}
