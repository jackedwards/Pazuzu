#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "ShaderProgram.hpp"
#include "PositionAttribute.hpp"
#include "ColorAttribute.hpp"
#include "TextureAttribute.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

int main()
{
    GLFWwindow* window;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    window = glfwCreateWindow(800, 600, "Test", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    
    Vertex vertices[] = {
        Vertex(Vector2f(-0.5f, 0.5f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector2f(0.5f, 0.5f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector2f(0.5f, -0.5f), Vector2f(1.0f, 1.0f)),
        Vertex(Vector2f(-0.5f, -0.5f), Vector2f(0.0f, 1.0f))
    };
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    GLuint ebo;
    glGenBuffers(1, &ebo);
    
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    VertexShader vertShader("vertex-shader.glsl");
    FragmentShader fragShader("fragment-shader.glsl");
    ShaderProgram shaderProgram(vertShader, fragShader);

    PositionAttribute posAttrib(shaderProgram.GetAttribute("position"));
    ColorAttribute colAttrib(shaderProgram.GetAttribute("color"));
    TextureAttribute texAttrib(shaderProgram.GetAttribute("texcoord"));
    
    Texture texture("guy.bmp");
    
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }
        
        glfwPollEvents();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
    }
    
    //glDeleteTextures(1, &tex);
    texture.Delete();

    shaderProgram.Delete();
    fragShader.Delete();
    vertShader.Delete();
    
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    
    glDeleteVertexArrays(1, &vao);
}