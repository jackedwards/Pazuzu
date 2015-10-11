#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Keyboard
{
public:
	static GLboolean m_keys[1024];

public:
	static GLboolean IsKeyPressed(int key);
private:
	Keyboard();
};

#endif