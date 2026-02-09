#include <Headers/autosVictory.h>
#include <Headers/utils.h>

#define BLINK 25

void autoVictroy(CRGB* leds, uint16_t led_count)
{
	static uint8_t tick = 0;

	tick++;
	if (tick > BLINK * 2)
	{
		tick = 0;
	}

	for (uint16_t i = 0; i < led_count; i++)
	{
		leds[i] = tick < BLINK ? CRGB(255, 0, 0) : CRGB(10, 0, 0);
	}
}