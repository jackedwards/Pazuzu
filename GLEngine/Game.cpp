#include "Game.hpp"

Game::Game(GLuint width, GLuint height)
	: m_state(GAME_ACTIVE), m_keys(), m_width(width), m_height(height)
{
	mp_background = std::make_shared<GameObject>(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);

	for (size_t i = 0; i < 700; ++i)
	{
		m_gameObjects.push_back(std::make_shared<GameObject>());
	}

	std::default_random_engine generator;
	std::uniform_real_distribution<double> xDist(0, 750);
	std::uniform_real_distribution<double> yDist(0, 550);

	for (auto& gameObject : m_gameObjects)
	{
		int x = xDist(generator);
		int y = yDist(generator);

		gameObject->m_transform.SetSize(50, 50);
		gameObject->m_transform.SetPosition(x, y);
	}
}

void Game::Init()
{
	mp_background->AddComponent<SpriteComponent>();
	mp_background->GetComponent<SpriteComponent>()->SetTexture(ResourceManager::GetTexture("bliss"));

	for (auto& gameObject : m_gameObjects)
	{
		gameObject->AddComponent<SpriteComponent>();
		gameObject->GetComponent<SpriteComponent>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	}

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
	for (auto& gameObject : m_gameObjects)
	{
		gameObject->m_transform.Move(gameObject->m_velocity);
		gameObject->m_transform.Rotate(10.0f * dt);

		glm::vec2 pos = gameObject->m_transform.GetPosition();
		glm::vec2 size = gameObject->m_transform.GetSize();

		if (pos.x + size.x >= 800 || pos.x <= 0)
			gameObject->m_velocity.x = -gameObject->m_velocity.x;
		if (pos.y + size.y >= 600 || pos.y <= 0)
			gameObject->m_velocity.y = -gameObject->m_velocity.y;
	}
}

void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
	mp_renderer->Draw(mp_background);

	for (auto& gameObject : m_gameObjects)
		if (gameObject->HasComponent<SpriteComponent>())
			mp_renderer->Draw(gameObject);
}