#include "Color.h"

/*
	To convert a color from rgb 1 - 255 format to rgb 0.0 - 1.0 format you need to divide the number by 255
	For example 59/255, 118/255, 255/255 = 0.23F, 0.46F, 1.0F
*/

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
	this->red = red / 255.0F;
	this->green = green / 255.0F;
	this->blue = blue / 255.0F;
	this->alpha = alpha / 255.0F;
};