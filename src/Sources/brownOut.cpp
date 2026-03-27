#include <Headers/brownOut.h>

#define FADE_TICKS 100

#define COLOR_A CRGB(0, 255, 0)
#define COLOR_B CRGB(0, 20, 0)

void brownOutLights(CRGB* leds, uint8_t led_count)
{
	static uint16_t ticks = 0;
	
	ticks++;
	if (ticks > FADE_TICKS * 2)
	{
		ticks = 0;
	}

	for (uint8_t i = 0; i < led_count; i++)
	{
		leds[i] = (ticks <= FADE_TICKS) ? COLOR_A : COLOR_B;
	}
}