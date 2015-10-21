#include "RectangleCollider.hpp"

RectangleCollider::RectangleCollider(GameObject* gameObject)
	: Component(gameObject), m_collision(gameObject)
{

}

void RectangleCollider::Start()
{
	
}

void RectangleCollider::Update()
{
	m_size = mp_gameObject->m_transform.GetSize();
	m_position = mp_gameObject->m_transform.GetPosition();
}

GLboolean RectangleCollider::CollidingWith(std::shared_ptr<RectangleCollider>& other)
{
	bool xCollision = (m_position.x + m_size.x) >= other->m_position.x &&
					   (other->m_position.x + other->m_size.x) >= m_position.x;
	bool yCollision = (m_position.y + m_size.y) >= other->m_position.y &&
					   (other->m_position.y + other->m_size.y) >= m_position.y;

	if (xCollision && yCollision)
	{
		if (m_position.x <= other->m_position.x)
		{
			m_collision.m_intersection.x = (m_position.x + m_size.x) - other->m_position.x;
		}
		else
		{
			m_collision.m_intersection.x = (other->m_position.x + other->m_size.x) - m_position.x;
		}

		if (m_position.y <= other->m_position.y)
		{
			m_collision.m_intersection.y = (m_position.y + m_size.y) - other->m_position.y;
		}
		else
		{
			m_collision.m_intersection.y = (other->m_position.y + other->m_size.y) - m_position.y;
		}
	}

	return xCollision && yCollision;
}