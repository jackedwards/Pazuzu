#include "ShaderProgram.hpp"

/**
 * @brief Creates a shader program
 */
ShaderProgram::ShaderProgram()
{
    m_program = glCreateProgram();
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
    m_program = glCreateProgram();
    glAttachShader(m_program, vert.m_shader);
    glAttachShader(m_program, frag.m_shader);
}

/**
 * @brief Attaches a shader to the shader program
 *
 * @param shader The shader to be attached
 */
void ShaderProgram::Attach(Shader& shader)
{
    glAttachShader(m_program, shader.m_shader);
}

/**
 * @brief Links the shader program and installs it as part
 *        of the current rendering state
 */
void ShaderProgram::Use()
{
    glLinkProgram(m_program);
    glUseProgram(m_program);
}

/**
 * @brief Deletes the shader program
 */
void ShaderProgram::Delete()
{
    glDeleteProgram(m_program);
}

/**
 * @brief Returns the location of an attribute variable
 *        with the specified name
 *
 * @param attribName The name of the attribute variable
 */
GLint ShaderProgram::GetAttribLocation(const std::string& attribName)
{
    return glGetAttribLocation(m_program, attribName.c_str());
}