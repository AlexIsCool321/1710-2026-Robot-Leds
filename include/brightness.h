#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <FastLED.h>

extern const unsigned int brightness;

CRGB colorRange(CRGB pColorA, CRGB pColorB, unsigned int pPercentage);

CRGB getBrightenedColor(CRGB pColor);

#endif