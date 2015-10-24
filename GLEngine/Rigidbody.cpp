#include "Rigidbody.hpp"

Rigidbody::Rigidbody(GameObject* gameObject) : Component(gameObject)
{
	
}

void Rigidbody::Start()
{
	m_velocity = glm::vec2(0.0f, 0.0f);
	m_gravity = 1.0f;
}

void Rigidbody::Update()
{
	m_velocity.y += m_gravity;

	mp_gameObject->Move(m_velocity);
}

void Rigidbody::OnCollisionEnter(Collision collision)
{
	
}