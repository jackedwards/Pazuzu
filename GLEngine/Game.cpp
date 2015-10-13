#include "Game.hpp"

Game::Game(GLuint width, GLuint height) : m_state(GAME_ACTIVE), m_width(width), m_height(height)
{
	mp_background = std::make_shared<GameObject>(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);
	mp_player = std::make_shared<GameObject>(glm::vec2(0, 0), glm::vec2(100, 100), 0.0f);
	mp_player->AddChild(glm::vec2(0, 0), glm::vec2(50, 50), 90.0f);
}

void Game::Init()
{
	mp_background->AddComponent<Transform>();
	mp_player->AddComponent<Transform>();
	mp_player->m_children[0]->AddComponent<Transform>();

	mp_background->AddComponent<Sprite>();
	mp_player->AddComponent<Sprite>();
	mp_player->m_children[0]->AddComponent<Sprite>();

	mp_player->AddComponent<PlayerMove>();

	mp_background->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("bliss"));
	mp_player->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	mp_player->m_children[0]->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("bliss"));

	mp_background->GetComponent<Transform>()->SetSize(glm::vec2(800, 600));
	mp_player->GetComponent<Transform>()->SetPosition(glm::vec2(100, 100));
	mp_player->GetComponent<Transform>()->SetSize(glm::vec2(100, 100));

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
	for (auto& kv : mp_player->m_components)
		kv.second->Update();
}

void Game::Render()
{
	if (mp_background->HasComponent<Sprite>())
		mp_renderer->Draw(mp_background);
	if (mp_player->HasComponent<Sprite>())
		mp_renderer->Draw(mp_player);
	if (mp_player->m_children[0]->HasComponent<Sprite>())
		mp_renderer->Draw(mp_player->m_children[0]);
}