#ifndef BRGCOLOR_H
#define BRGCOLOR_H

#include "./Color.h"

typedef byte color_t;
typedef uint32_t long_color_t;

class BRGColor : public Color
{
	// using Color::Color;

	public:
		virtual operator long_color_t() const;

		BRGColor(color_t, color_t, color_t);
		BRGColor(long_color_t);
};

#endif