#include <Headers/brownOut.h>

#define FADE_TICKS 50

#define COLOR_A CRGB(123, 63, 0)
#define COLOR_B CRGB(0, 0, 0)

void brownOutLights(CRGB* leds, uint8_t led_count)
{
	static uint16_t ticks = 0;
	
	ticks++;
	if (ticks > FADE_TICKS)
	{
		ticks = 0;
	}

	for (uint8_t i = 0; i < led_count; i++)
	{
		float percentage = (FADE_TICKS - ticks) / FADE_TICKS;

		leds[i].r = (percentage * COLOR_A.r) + ((1-percentage) * COLOR_B.r);
		leds[i].g = (percentage * COLOR_A.g) + ((1-percentage) * COLOR_B.g);
		leds[i].b = (percentage * COLOR_A.b) + ((1-percentage) * COLOR_B.b);
	}
}