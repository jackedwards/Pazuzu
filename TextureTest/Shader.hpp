#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <streambuf>

class Shader
{
    friend class ShaderProgram;

protected:
    GLuint m_shader;

public:
    virtual ~Shader() = 0;
    void Delete();
protected:
    std::string LoadSourceFromFile(const std::string& fileName);
    void SetSource(const char* source);
    void Compile();
};

inline Shader::~Shader() {};

#endif
