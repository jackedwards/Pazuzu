#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <GL/glew.h>

#pragma pack(1)

struct BitmapFileHeader
{
    int16_t bfType;
    int32_t bfSize;
    int16_t bfReserved1;
    int16_t bfReserved2;
    int32_t bfOffBits;
};

struct BitmapInfoHeader
{
    int32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    int16_t biPlanes;
    int16_t biBitCount;
    int32_t biCompression;
    int32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    int32_t biClrUsed;
    int32_t biClrImportant;
    
};

struct RgbData
{
    GLubyte rgbBlue;
    GLubyte rgbGreen;
    GLubyte rgbRed;
};

class Bitmap
{
    friend class Texture;

public:
    GLboolean m_isValid;
    GLint m_fileSize;
    GLint m_width;
    GLint m_height;
    GLint m_bitDepth;
private:
    BitmapFileHeader m_fileHeader;
    BitmapInfoHeader m_infoHeader;
    std::vector<RgbData> m_pixelData;

public:
    Bitmap(const std::string&);
    void Load(const std::string& name);
    void LoadFileHeader(std::ifstream& file);
    void LoadInfoHeader(std::ifstream& file);
    void LoadData(std::ifstream& file);
    GLboolean IsBitmap();
    GLboolean IsValidBitDepth();
};

#endif
