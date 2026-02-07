#ifndef ENABLED_H
#define ENABLED_H

#include <stdint.h>
#include <FastLED.h>

void enabledLights(bool enabled, CRGB* leds, uint8_t led_count);

#endif