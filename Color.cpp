
#include "Color.h"

Color::Color(color_t red, color_t green, color_t blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::Color(long_color_t rgbColor)
{
	this->red = rgbColor >> 16;
	this->green = (rgbColor >> 8) & 255;
	this->blue = rgbColor & 255;
}

void Color::darken(color_t darkenLiteral)
{
	this->red = (red > darkenLiteral) ? red - darkenLiteral : 0;
	this->green = (green > darkenLiteral) ? green - darkenLiteral : 0;
	this->blue = (blue > darkenLiteral) ? blue - darkenLiteral : 0;
}

void Color::lighten(color_t lightenLiteral)
{
	this->red = (red + lightenLiteral <= 255) ? red + lightenLiteral : 255;
	this->green = (green + lightenLiteral <= 255) ? green + lightenLiteral : 255;
	this->blue = (blue + lightenLiteral <= 255) ? blue + lightenLiteral : 255;
}