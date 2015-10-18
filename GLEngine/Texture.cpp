#include "Texture.hpp"

/**
 * @brief Default constructor.
 */
Texture::Texture()
	: m_width(0), m_height(0), m_internalFormat(GL_RGB), m_imageFormat(GL_RGB), m_wrapS(GL_REPEAT), m_wrapT(GL_REPEAT), m_filterMin(GL_NEAREST), m_filterMax(GL_NEAREST)
{

}

/**
 * @brief Creates a texture from a bitmap file
 *
 * @param fileName The name of the bitmap file to use
 */
Texture::Texture(const std::string& fileName)
	: m_width(0), m_height(0), m_internalFormat(GL_RGB), m_imageFormat(GL_RGB), m_wrapS(GL_REPEAT), m_wrapT(GL_REPEAT), m_filterMin(GL_NEAREST), m_filterMax(GL_NEAREST)
{
    LoadFromFile(fileName);
}

/**
 * @brief Destructor.
 *
 */
Texture::~Texture()
{
	Delete();
}

/**
 * @brief Initialises the pixel data using the specified bitmap
 *
 * @param bitmap The bitmap to be used
 */
void Texture::LoadFromBitmap(const Bitmap& bitmap)
{
    if (bitmap.m_isValid)
	{
        m_width = bitmap.m_width;
        m_height = bitmap.m_height;
        
        GLsizei numPixels = m_width * m_height;
        m_pixels.reserve(numPixels);
        
        for (size_t i = 0; i < numPixels; ++i)
		{
            GLuint r = bitmap.m_pixelData[i].rgbRed;
            GLuint g = bitmap.m_pixelData[i].rgbGreen;
            GLuint b = bitmap.m_pixelData[i].rgbBlue;
            
            m_pixels.push_back(Color(r, g, b).Normalise());
        }
    }
}

void Texture::LoadFromPNG(const std::string& fileName)
{
    /*mp_data = stbi_load(fileName.c_str(), &m_width, &m_height, &m_bpp, 4);

    if (mp_data == nullptr)
        throw("Failed to load texture.\n");*/
}

/**
 * @brief Creates a bitmap from the specified file name and then initialises the pixel data
 *
 * @param fileName The name of the bitmap file
 */
void Texture::LoadFromFile(const std::string& fileName)
{
    Bitmap bitmap(fileName);
    LoadFromBitmap(bitmap);
    //LoadFromPNG(fileName);
	Generate();
}

/**
 * @brief Generates a texture and sets its parameters
 */
void Texture::Generate()
{
    glGenTextures(1, &this->m_id);

	glBindTexture(GL_TEXTURE_2D, this->m_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->m_wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->m_wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->m_filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->m_filterMax);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_FLOAT, reinterpret_cast<GLchar*>(m_pixels.data()));
	glBindTexture(GL_TEXTURE_2D, 0);
}

/*
 * @brief Binds the texture as the current active GL_TEXTURE_2D object
 */
void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->m_id);
}

/**
 * @brief Deletes the texture
 */
void Texture::Delete()
{
    glDeleteTextures(1, &this->m_id);
    //stbi_image_free(mp_data);
}