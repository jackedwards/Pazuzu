#include "Color.hpp"

const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);

/**
 * @brief Creates a color and sets each value to 1.0f
 */
Color::Color() : r(1.0f), g(1.0f), b(1.0f)
{
    
}

/**
 * @brief Creates a color using the specified RGB values
 *
 * @param R The red value (0.0f - 1.0f)
 * @param G The green value (0.0f - 1.0f)
 * @param B The blue value (0.0f - 1.0f)
 */
Color::Color(GLfloat R, GLfloat G, GLfloat B) : r(R), g(G), b(B)
{
    
}

/**
 * @brief Divides each color value by the specified number
 *
 * @param left The dividends (R, G and B values)
 * @param right The divisor
 *
 * @return
 */
Color operator/(const Color& left, const GLfloat right)
{
    return Color(left.r / 255,
            left.g / 255,
            left.b / 255);
}

/**
 * @brief Converts the color values from a value between 0..255 to a value between 0..1
 *
 * @return A Color object with the normalised values
 */
Color Color::Normalise() const
{
    return (*this) / 255;
}