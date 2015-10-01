#ifndef FRAGMENTSHADER_HPP
#define FRAGMENTSHADER_HPP

#include "Shader.hpp"

class FragmentShader : public Shader
{
public:
    FragmentShader(const std::string& fileName);
	~FragmentShader();
};

#endif
