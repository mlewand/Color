
#include "Color.h"

#ifndef max
// ESP8266 driver defines it's own max implementation, which prevents me from using pure stdlib implementation.
// https://github.com/esp8266/Arduino/issues/398
#include <stdlib.h>
#define _color_max(a, b) std::max(a, b)
#define _color_min(a, b) std::min(a, b)
#else
#define _color_max(a, b) max(a, b)
#define _color_min(a, b) min(a, b)
#endif

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

Color *Color::darken(color_t darkenLiteral)
{
	this->red = (red > darkenLiteral) ? red - darkenLiteral : 0;
	this->green = (green > darkenLiteral) ? green - darkenLiteral : 0;
	this->blue = (blue > darkenLiteral) ? blue - darkenLiteral : 0;

	return this;
}

Color *Color::lighten(color_t lightenLiteral)
{
	this->red = (red + lightenLiteral <= 255) ? red + lightenLiteral : 255;
	this->green = (green + lightenLiteral <= 255) ? green + lightenLiteral : 255;
	this->blue = (blue + lightenLiteral <= 255) ? blue + lightenLiteral : 255;

	return this;
}

Color *Color::blend(const Color *other, byte percentage)
{
	percentage = _color_min(percentage, 100);
	percentage = _color_max(percentage, 0);

	this->red = ((double)other->red * percentage / 100) + ((double)this->red * (100 - percentage) / 100);
	this->green = ((double)other->green * percentage / 100) + ((double)this->green * (100 - percentage) / 100);
	this->blue = ((double)other->blue * percentage / 100) + ((double)this->blue * (100 - percentage) / 100);

	return this;
}

Color::operator long_color_t() const
{
	return ((long_color_t)this->red << 16) | ((long_color_t)this->green << 8) | this->blue;
}

// Do not leave preprocessor garbage.
#undef _color_max
#undef _color_min