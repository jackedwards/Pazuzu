#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <GL/glew.h>
#include "glm/glm.hpp"

class Transform
{
private:
	glm::vec2 m_position;
	glm::vec2 m_size;
	GLfloat m_rotation;

public:
	Transform();
	Transform(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	void Move(const glm::vec2& position);
	void Move(const GLfloat& x, const GLfloat& y);
	void Scale(const glm::vec2& scale);
	void Scale(const GLfloat& x, const GLfloat& y);
	void Rotate(const GLfloat& rotation);
	void SetPosition(const glm::vec2 position);
	void SetPosition(const GLfloat x, const GLfloat y);
	void SetSize(const glm::vec2 size);
	void SetSize(const GLfloat x, const GLfloat y);
	void SetRotation(const GLfloat rotation);
	const glm::vec2& GetPosition() const;
	const glm::vec2& GetSize() const;
	const GLfloat& GetRotation() const;
};

#endif