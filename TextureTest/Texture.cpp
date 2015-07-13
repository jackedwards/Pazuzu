#include "Texture.hpp"

Texture::Texture(const Bitmap& bitmap)
{
    LoadFromBitmap(bitmap);
    
    GenerateTexture();
}

Texture::Texture(const std::string& fileName)
{
    LoadFromFile(fileName);
    
    GenerateTexture();
}

void Texture::LoadFromBitmap(const Bitmap& bitmap)
{
    if (bitmap.m_isValid) {
        m_width = bitmap.m_width;
        m_height = bitmap.m_height;
        
        GLsizei numPixels = m_width * m_height;
        m_pixels.reserve(numPixels);
        
        for (GLint i = 0; i < numPixels; ++i) {
            GLuint r = bitmap.m_pixelData[i].rgbRed;
            GLuint g = bitmap.m_pixelData[i].rgbGreen;
            GLuint b = bitmap.m_pixelData[i].rgbBlue;
            
            m_pixels.push_back(Color(r, g, b).Normalise());
        }
    }
}

void Texture::LoadFromFile(const std::string& fileName)
{
    Bitmap bitmap(fileName);
    LoadFromBitmap(bitmap);
}

void Texture::GenerateTexture()
{
    glGenTextures(1, &m_texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_FLOAT, reinterpret_cast<GLchar*>(m_pixels.data()));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void Texture::Delete()
{
    glDeleteTextures(1, &m_texId);
}