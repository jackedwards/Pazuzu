#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <vector>
#include <memory>
#include "ErrorLogger.hpp"
#include "Bitmap.hpp"
#include "Color.hpp"

#pragma pack(1)

class Texture
{
public:
    std::vector<Color> m_pixels;
    GLuint m_width, m_height;
	GLuint m_internalFormat;
	GLuint m_imageFormat;
	GLuint m_wrapS, m_wrapT;
	GLuint m_filterMin, m_filterMax;
private:
	GLuint m_id;

public:
	Texture();
    Texture(const std::string& name);
	~Texture();
    void LoadFromBitmap(const Bitmap& bitmap);
    void LoadFromFile(const std::string& fileName);
    void Generate();
	void Bind() const;
    void Delete();
};

#endif
