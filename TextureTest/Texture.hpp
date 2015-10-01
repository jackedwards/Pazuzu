#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <vector>
#include "Bitmap.hpp"
#include "Color.hpp"

#pragma pack(1)

class Texture
{
public:
    std::vector<Color> m_pixels;
    GLint m_width;
    GLint m_height;
private:
    GLuint m_texId;

public:
    Texture(const Bitmap& bitmap);
    Texture(const std::string& name);
    void LoadFromBitmap(const Bitmap& bitmap);
    void LoadFromFile(const std::string& fileName);
    void GenerateTexture();
    void Delete();
};

#endif
