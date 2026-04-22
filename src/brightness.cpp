#include <brightness.h>

const unsigned int brightness = 10;

CRGB colorRange(CRGB pColorA, CRGB pColorB, unsigned int pPercentage)
{
	CRGB result = {0};

	float percentage = float(pPercentage) / 100.0f;

	result.r = (pColorA.r * percentage) + (pColorB.r * (1 - percentage));
	result.g = (pColorA.g * percentage) + (pColorB.g * (1 - percentage));
	result.b = (pColorA.b * percentage) + (pColorB.b * (1 - percentage));

	return result;
}

CRGB getBrightenedColor(CRGB pColor)
{
	CRGB result = {0};

	float bright = float(brightness)/100.0f;

	result.r = pColor.r * bright;
	result.g = pColor.g * bright;
	result.b = pColor.b * bright;

	return result;
}