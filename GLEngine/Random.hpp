#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <GL/glew.h>

class Random
{
public:
	Random();
	static GLfloat GetRandomNumber(GLfloat lower, GLfloat upper);
	static GLint GetRandomNumber(GLint lower, GLint upper);
};

#endif