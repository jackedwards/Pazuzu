#include "LevelManager.hpp"

std::vector<std::shared_ptr<Level> > LevelManager::m_levels;
std::shared_ptr<Level> LevelManager::m_currentLevel;

LevelManager::LevelManager() { }

void LevelManager::Init()
{
	m_currentLevel = nullptr;

	m_levels.push_back(std::make_shared<MainLevel>("MainLevel"));
	m_levels.push_back(std::make_shared<TestLevel>("TestLevel"));
}

std::shared_ptr<Level>& LevelManager::GetCurrentLevel()
{
	return m_currentLevel;
}

void LevelManager::SetCurrentLevel(std::string name)
{
	for (auto& level : m_levels)
	{
		if (level->GetName() == name)
		{
			m_currentLevel = level;
			m_currentLevel->Init();	
			return;
		}
	}

	std::cout << "Level '" << name << "' does not exist.\n";
}

void LevelManager::Update(GLfloat dt)
{
	m_currentLevel->Update(dt);
}

void LevelManager::Render(SpriteRenderer* renderer)
{
	m_currentLevel->Render(renderer);
}
