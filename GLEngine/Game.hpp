#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ErrorLogger.hpp"
#include "SpriteRenderer.hpp"
#include "ShaderProgram.hpp"
#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "Sprite.hpp"
#include "ResourceManager.hpp"
#include "GameObject.hpp"

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	GameState m_state;
	GLboolean m_keys[1024];
	GLuint m_width, m_height;
	GameObject m_player;
	GameObject m_background;

private:
	SpriteRenderer* mp_renderer;

public:
	Game(GLuint width, GLuint height);
	void Init();
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
};

#endif