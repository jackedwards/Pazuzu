#include "Random.hpp"

Random::Random()
{
	
}

// Lower inclusive, upper exclusive
GLfloat Random::GetRandomNumber(GLfloat lower, GLfloat upper)
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<GLfloat> dist(lower, upper);

    return dist(mt);
}

// Lower inclusive, upper exclusive
GLint Random::GetRandomNumber(GLint lower, GLint upper)
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<GLfloat> dist(lower, upper);

    return (GLint)dist(mt);
}
