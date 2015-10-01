#ifndef ERRORLOGGER_HPP
#define ERRORLOGGER_HPP

#include <GL/glew.h>
#include <cstdio>
#include <string>

class ErrorLogger
{
public:
	static void CheckForErrors(std::string text);
};

#endif