#include "Game.hpp"

Game::Game(GLuint width, GLuint height) : m_state(GAME_ACTIVE), m_width(width), m_height(height)
{
	mp_background = std::make_shared<GameObject>(glm::vec2(0, 0), glm::vec2(800, 600), 0.0f);

	std::shared_ptr<GameObject> player = std::make_shared<GameObject>(glm::vec2(0, 0), glm::vec2(100, 100), 0.0f);
	std::shared_ptr<GameObject> enemy = std::make_shared<GameObject>(glm::vec2(300, 300), glm::vec2(100, 100), 0.0f);

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
}

void Game::Init()
{
	mp_background->AddComponent<Sprite>();
	mp_background->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("bliss"));

	for (std::shared_ptr<GameObject>& gameObject : m_gameObjects)
	{
		gameObject->AddComponent<Sprite>();
		gameObject->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
		gameObject->AddComponent<RectangleCollider>();
	}

	m_gameObjects[0]->AddComponent<PlayerMove>();

	//mp_player->AddComponent<Sprite>();
	//mp_player->GetComponent<Sprite>()->SetTexture(ResourceManager::GetTexture("awesomeface"));
	//mp_player->AddComponent<PlayerMove>();

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
	//for (auto& kv : mp_player->m_components)
	//	kv.second->Update();

	for (auto& gameObject : m_gameObjects)
		for (auto& kv : gameObject->m_components)
			kv.second->Update();

	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		for (int j = 0; j < m_gameObjects.size(); ++j)
		{
			if (m_gameObjects[i] != m_gameObjects[j])
				CheckCollisions(m_gameObjects[i], m_gameObjects[j]);
		}
	}
}

void Game::Render()
{
	if (mp_background->HasComponent<Sprite>())
		mp_renderer->Draw(mp_background);
	//if (mp_player->HasComponent<Sprite>())
	//	mp_renderer->Draw(mp_player);

	for (auto& gameObject : m_gameObjects)
		if (gameObject->HasComponent<Sprite>())
			mp_renderer->Draw(gameObject);
}

void Game::CheckCollisions(std::shared_ptr<GameObject>& objectA, std::shared_ptr<GameObject>& objectB)
{
	if (objectA->HasComponent<RectangleCollider>() && objectB->HasComponent<RectangleCollider>())
	{
		std::shared_ptr<RectangleCollider> colliderA = objectA->GetComponent<RectangleCollider>();
		std::shared_ptr<RectangleCollider> colliderB = objectB->GetComponent<RectangleCollider>();

		if (colliderA->CollidingWith(colliderB))
		{
			for (auto& kv : objectA->m_components)
				kv.second->OnCollisionEnter(); // Change collider to Collision object
		}
	}
}