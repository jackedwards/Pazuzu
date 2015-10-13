#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Component.hpp"

class Transform : public Component
{
public:
	glm::vec2 m_position;
	glm::vec2 m_size;
	GLfloat m_rotation;
	glm::vec2 m_localPosition;
	glm::vec2 m_localSize;
	GLfloat m_localRotation;

public:
	Transform();
	virtual void Start() override;
	virtual void Update() override;
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
	const glm::vec2& GetLocalPosition() const;
	const glm::vec2& GetLocalSize() const;
	const GLfloat& GetLocalRotation() const;
};

#endif