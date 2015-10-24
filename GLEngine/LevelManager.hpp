#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include "Level.hpp"
#include "MainLevel.hpp"
#include "TestLevel.hpp"

class LevelManager
{
private:
	static std::vector<std::shared_ptr<Level> > m_levels;
	static std::shared_ptr<Level> m_currentLevel;

public:
	static void Init();
	static std::shared_ptr<Level>& GetCurrentLevel();
	static void SetCurrentLevel(std::string name);
	static void Update(GLfloat dt);
	static void Render(SpriteRenderer* renderer);
private:
	LevelManager();
};

#endif
