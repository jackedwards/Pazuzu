#include "Keyboard.hpp"

GLboolean Keyboard::m_keys[1024];

Keyboard::Keyboard() { }

GLboolean Keyboard::IsKeyPressed(int key)
{
	return m_keys[key];
}