#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <vector>
#include <memory>
#include <GL/glew.h>
#include "ErrorLogger.hpp"
#include "Bitmap.hpp"
#include "Color.hpp"
//#include "stb_image.h"

#pragma pack(1)

class Texture
{
public:
    std::vector<Color> m_pixels;
    //unsigned char* mp_data;
    GLint m_width, m_height;
    GLint m_bpp;
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
    void LoadFromPNG(const std::string& fileName);
    void LoadFromFile(const std::string& fileName);
    void Generate();
	void Bind() const;
    void Delete();
};

#endif
