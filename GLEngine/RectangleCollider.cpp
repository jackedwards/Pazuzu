#include "RectangleCollider.hpp"

RectangleCollider::RectangleCollider()
{
	
}

void RectangleCollider::Start()
{
	
}

void RectangleCollider::Update()
{
	
}

GLboolean RectangleCollider::CollidingWith(RectangleCollider& other)
{
	bool xCollision = (m_position.x + m_size.x) >= other.m_position.x &&
					   (other.m_position.x + other.m_size.x) >= m_position.x;
	bool yCollision = (m_position.y + m_size.y) >= other.m_position.y &&
					   (other.m_position.y + other.m_size.y) >= m_position.y;

	return xCollision && yCollision;
}