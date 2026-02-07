#ifndef FLYWHEEL_H
#define FLYWHEEL_H

#include <stdint.h>
#include <FastLED.h>

void flywheelChargeLights(uint8_t chargePercentage, CRGB* leds, uint8_t led_count);

#endif