#include "Shader.hpp"

/**
 * @brief  Returns shader source code loaded from a file with the specified filename
 *
 * @param  fileName Name of the shader source code file
 * @return Shader source code if the file opened successfully,
 *         otherwise an empty string
 */
std::string Shader::LoadSourceFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    
    if (file.is_open()) {
        std::string source((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
        
        file.close();
        
        return source;
    }
    else {
        printf("Failed to open %s\n", fileName.c_str());
        
        return "";
    }
}

/**
 * @brief Sets the source code for the shader
 *
 * @param source Source code for the shader
 */
void Shader::SetSource(const char* source)
{
    glShaderSource(m_id, 1, &source, NULL);
}

/**
 * @brief Compiles the shader
 */
void Shader::Compile()
{
    GLint status;
    char buffer[512];

    glCompileShader(m_id);
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);
    glGetShaderInfoLog(m_id, 512, NULL, buffer);

    if (status) {
        printf("Shader compilation succeeded!\n");
    }
    else {
        printf("Shader compilation failed: %s\n", buffer);
    }
}

/**
 * @brief Deletes the shader
 */
void Shader::Delete()
{
    glDeleteShader(m_id);
}