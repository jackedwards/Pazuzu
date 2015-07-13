/*--------------------------------------------------------*/
/* CURRENTLY ONLY SUPPORTS UNCOMPRESSED, 24-BIT BMP FILES */
/*--------------------------------------------------------*/

#include "Bitmap.hpp"

Bitmap::Bitmap(const std::string& name)
{
    m_isValid = false;
    Load(name);
}

void Bitmap::Load(const std::string& name)
{
    std::ifstream file(name, std::ios::binary);
    
    if (file.is_open()) {
        LoadFileHeader(file);
        LoadInfoHeader(file);
        
        if (IsBitmap()) {
            if (IsValidBitDepth()) {
                LoadData(file);
                m_isValid = true;
            }
        }

        file.close();
    }
    else {
        printf("Failed to open %s\n", name.c_str());
    }
}

void Bitmap::LoadFileHeader(std::ifstream& file)
{
    file.read((GLchar*)&m_fileHeader, sizeof(m_fileHeader));

    m_fileSize = m_fileHeader.bfSize;
}

void Bitmap::LoadInfoHeader(std::ifstream& file)
{
    file.read((GLchar*)&m_infoHeader, sizeof(m_infoHeader));

    m_width = m_infoHeader.biWidth;
    m_height = m_infoHeader.biHeight;
    m_bitDepth = m_infoHeader.biBitCount;
}

void Bitmap::LoadData(std::ifstream& file)
{
    GLsizei numPixels = m_infoHeader.biWidth * m_infoHeader.biHeight;
    GLsizei numRows = m_infoHeader.biHeight;
    // rows are padded to be multiples of 4
    // the padding is calculated so that it can be ignored
    GLsizei padding = (m_infoHeader.biWidth * 3) % 4;
    GLsizei pixelsPerRow = m_infoHeader.biWidth;
    GLsizei bytesPerRow = pixelsPerRow * 3;

    m_pixelData.reserve(numPixels);
    file.seekg(m_fileHeader.bfOffBits);
    
    // starts at end of the array and works towards the beginning
    // this is to counteract the fact that BMP pixel data is written
    // starting from the bottom-left of the image
    for (int i = numRows - 1; i >= 0; --i) {
        file.read(reinterpret_cast<GLchar*>(&m_pixelData[i * pixelsPerRow]), bytesPerRow);
        file.ignore(padding);
    }
}

GLboolean Bitmap::IsBitmap()
{
    GLboolean isBitmap = m_fileHeader.bfType == 0x4d42;

    if (!isBitmap) {
        printf("Loading failed: File is not a bitmap\n");
    }

    return isBitmap;
}

GLboolean Bitmap::IsValidBitDepth()
{
    GLboolean isValidBitDepth = m_infoHeader.biBitCount == 0x18;
    
    if (!isValidBitDepth) {
        printf("Loading failed: Bit depth is %i-bit (24-bit required)\n", m_infoHeader.biBitCount);
    }
    
    return isValidBitDepth;
}