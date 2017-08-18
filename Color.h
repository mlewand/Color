
#ifndef COLOR_H
#define COLOR_H

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
	void darken(color_t);

	// Lightens current color (all channels) by a given literal.
	void lighten(color_t);

	color_t getRed() const { return this->red; }
	color_t getGreen() const { return this->green; }
	color_t getBlue() const { return this->blue; }

	operator long_color_t() const { return ((long_color_t)this->red << 16) | ((long_color_t)this->green << 8) | this->blue; }
};

#endif