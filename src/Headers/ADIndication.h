#ifndef ADINDICATION_H
#define ADINDICATION_H

#include <stdint.h>
#include <FastLED.h>

void ADIndication(bool attacking, CRGB* leds, uint16_t led_count);

#endif