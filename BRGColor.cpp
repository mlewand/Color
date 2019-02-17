
#include "BRGColor.h"

BRGColor::BRGColor( color_t red, color_t green, color_t blue ) : Color::Color( red, green, blue )
{
}


BRGColor::BRGColor(long_color_t rgbColor) : Color::Color( rgbColor )
{
}

BRGColor::operator long_color_t() const
{
	return ((long_color_t)this->getBlue() << 16) | ((long_color_t)this->getRed() << 8) | this->getGreen();
}
