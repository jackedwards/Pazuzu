#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "ErrorLogger.hpp"

class ShaderProgram
{
private:
    GLuint m_id;

public:
    ShaderProgram();
    ShaderProgram(VertexShader& vert, FragmentShader& frag);
	~ShaderProgram();
    void Attach(Shader& shader);
    void Detach(Shader& shader);
    ShaderProgram& Use();
    void Delete();
    GLint GetAttribLocation(const std::string& name);
	GLint GetUniformLocation(const std::string& name);
    void SetFloat(const std::string& name, GLfloat value);
    void SetInteger(const std::string& name, GLint value);
    void SetVector2f(const std::string& name, GLfloat x, GLfloat y);
    void SetVector2f(const std::string& name, const glm::vec2& value);
    void SetVector3f(const std::string& name, GLfloat x, GLfloat y, GLfloat z);
    void SetVector3f(const std::string& name, const glm::vec3& value);
    void SetVector4f(const std::string& name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void SetVector4f(const std::string& name, const glm::vec4& value);
    void SetMatrix4(const std::string& name, const glm::mat4& matrix);
};

#endif
