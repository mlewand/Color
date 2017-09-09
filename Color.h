
#ifndef COLOR_H
#define COLOR_H

#include "Arduino.h"

typedef byte color_t;
typedef uint32_t long_color_t;

class Color
{
  private:
	color_t red;
	color_t green;
	color_t blue;

  public:
	Color(color_t, color_t, color_t);
	Color(long_color_t);

	// Darkens current color (all channels) by a given literal.
	Color *darken(color_t);

	// Lightens current color (all channels) by a given literal.
	Color *lighten(color_t);

	// percentage - 0-100 value - percentage of current color to be left in blend color.
	Color *blend(const Color *other, byte percentage);

	color_t getRed() const
	{
		return this->red;
	}
	color_t getGreen() const
	{
		return this->green;
	}
	color_t getBlue() const
	{
		return this->blue;
	}

	operator long_color_t() const;
	Color &operator=(const Color &otherColor);
};

#endif