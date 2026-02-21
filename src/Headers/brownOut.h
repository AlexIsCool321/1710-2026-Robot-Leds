#ifndef BROWNOUT_H
#define BROWNOUT_H

#include <stdint.h>
#include <FastLED.h>

void brownOutLights(CRGB* leds, uint8_t led_count);

#endif