#include "Shader.hpp"

void Shader::SetSource(const std::string& name)
{
    std::ifstream file(name);

    if (file.is_open()) {
        std::string source((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

        file.close();

        const char* s = source.c_str();
        glShaderSource(m_shader, 1, &s, NULL);
    }
    else {
        printf("Failed to open %s\n", name.c_str());
    }
}

void Shader::Compile()
{
    GLint status;
    char buffer[512];

    glCompileShader(m_shader);
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &status);
    glGetShaderInfoLog(m_shader, 512, NULL, buffer);

    if (status) {
        printf("Shader compilation succeeded!\n");
    }
    else {
        printf("Shader compilation failed: %s\n", buffer);
    }
}

void Shader::Delete()
{
    glDeleteShader(m_shader);
}