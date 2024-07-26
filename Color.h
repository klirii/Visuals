#pragma once
#include <iostream>

class Color {
public:
	float red = 0.0F;
	float green = 0.0F;
	float blue = 0.0F;
	float alpha = 0.0F;

	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255.0F);
};