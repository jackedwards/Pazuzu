#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <GL/glew.h>
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "SpriteRenderer.hpp"
#include "RectangleCollider.hpp"
#include "ResourceManager.hpp"

class Level
{
protected:
	std::vector<std::shared_ptr<GameObject> > m_gameObjects;

public:
	virtual void Init() = 0;
	void Update(GLfloat dt);
	void Render(SpriteRenderer* renderer);
	void CheckCollisions(std::shared_ptr<GameObject>& objectA, std::shared_ptr<GameObject>& objectB);
	void CreateObject();
	void CreateObject(std::string name);
	void CreateObject(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	void CreateObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation);
	const std::shared_ptr<GameObject> GetObject(const std::string name) const;
};

#endif