#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <GL/glew.h>
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "SpriteRenderer.hpp"
#include "RectangleCollider.hpp"
#include "Resources.hpp"

class Level
{
protected:
	std::vector<std::shared_ptr<GameObject> > m_gameObjects;
	std::vector<std::shared_ptr<GameObject> > m_gameObjectQueue;
	std::string m_name;

public:
	Level(std::string name);
	virtual void Init() = 0;
	void Update(GLfloat dt);
	void Render(SpriteRenderer* renderer);
	void CheckCollisions(std::shared_ptr<GameObject>& objectA, std::shared_ptr<GameObject>& objectB);
	std::shared_ptr<GameObject> CreateObject();
	std::shared_ptr<GameObject> CreateObject(std::string name);
	std::shared_ptr<GameObject> CreateObject(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	std::shared_ptr<GameObject> CreateObject(std::string name, glm::vec2 position, glm::vec2 size, GLfloat rotation);
	const std::shared_ptr<GameObject> GetObject(const std::string& name) const;
	const std::vector<std::shared_ptr<GameObject> > GetObjectsWithTag(const std::string& tag) const;
	const std::string& GetName() const;
private:
	void AddFromQueue();
};

#endif