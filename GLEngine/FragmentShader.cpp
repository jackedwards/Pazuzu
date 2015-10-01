#include "FragmentShader.hpp"

/**
 * @brief Creates and compiles a fragment shader
 *
 * @param fileName Name of the shader source code file
 */
FragmentShader::FragmentShader(const std::string& fileName)
{
    m_id = glCreateShader(GL_FRAGMENT_SHADER);
    std::string source = LoadSourceFromFile(fileName);
    SetSource(source.c_str());
    Compile();
}

/**
* @brief Destructor.
*
*/
FragmentShader::~FragmentShader()
{
	Delete();
}