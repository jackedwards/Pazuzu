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
	Sprite m_sprite1;
	Sprite m_sprite2;
	Texture m_texture1;
	Texture m_texture2;

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