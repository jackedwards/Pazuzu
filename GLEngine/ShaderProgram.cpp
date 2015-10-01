#include "ShaderProgram.hpp"

/**
 * @brief Creates a shader program
 */
ShaderProgram::ShaderProgram()
{
    m_id = glCreateProgram();
}

/**
 * @brief Creates a shader program and attaches a vertex
 *        shader and a fragment shader.
 *
 * @param vert A vertex shader
 * @param frag A fragment shader
 */
ShaderProgram::ShaderProgram(VertexShader& vert, FragmentShader& frag)
{
    m_id = glCreateProgram();
    glAttachShader(m_id, vert.m_id);
    glAttachShader(m_id, frag.m_id);
	glLinkProgram(this->m_id);
}

/**
* @brief Destructor.
*
*/
ShaderProgram::~ShaderProgram()
{
	Delete();
}

/**
 * @brief Attaches a shader to the shader program
 *
 * @param shader The shader to be attached
 */
void ShaderProgram::Attach(Shader& shader)
{
    glAttachShader(m_id, shader.m_id);
}

/**
 * @brief Links the shader program and installs it as part
 *        of the current rendering state
 */
void ShaderProgram::Use()
{
    glUseProgram(m_id);
}

/**
 * @brief Deletes the shader program
 */
void ShaderProgram::Delete()
{
    glDeleteProgram(m_id);
}

/**
 * @brief Returns the location of an attribute variable
 *        with the specified name
 *
 * @param attribName The name of the attribute variable
 */
GLint ShaderProgram::GetAttribLocation(const std::string& name)
{
    return glGetAttribLocation(m_id, name.c_str());
}

GLint ShaderProgram::GetUniformLocation(const std::string& name)
{
	return glGetUniformLocation(m_id, name.c_str());
}