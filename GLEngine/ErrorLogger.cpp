#include "ErrorLogger.hpp"

void ErrorLogger::CheckForErrors(const std::string& text)
{
	GLenum error = glGetError();

	switch (error)
	{
	case GL_NO_ERROR:
		break;
	case GL_INVALID_ENUM:
		printf("%s - ERROR: Invalid enum.\n", text.c_str());
		break;
	case GL_INVALID_VALUE:
		printf("%s - ERROR: Invalid value.\n", text.c_str());
		break;
	case GL_INVALID_OPERATION:
		printf("%s - ERROR: Invalid operation.\n", text.c_str());
		break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:
		printf("%s - ERROR: Invalid framebuffer operation.\n", text.c_str());
		break;
	case GL_OUT_OF_MEMORY:
		printf("%s - ERROR: Out of memory.\n", text.c_str());
		break;
	case GL_STACK_UNDERFLOW:
		printf("%s - ERROR: Stack underflow.\n", text.c_str());
		break;
	case GL_STACK_OVERFLOW:
		printf("%s - ERROR: Stack overflow.\n", text.c_str());
		break;
	}
}