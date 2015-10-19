#include "VertexShader.hpp"

/**
 * @brief Creates and compiles a vertex shader
 *
 * @param fileName Name of the shader source code file
 */
VertexShader::VertexShader(const std::string& fileName)
{
    m_id = glCreateShader(GL_VERTEX_SHADER); ErrorLogger::CheckForErrors("glCreateShader - vertex");
    std::string source = LoadSourceFromFile(fileName);
    SetSource(source.c_str());
    Compile();
}
