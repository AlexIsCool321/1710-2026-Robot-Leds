#include <Headers/enabled.h>
#include <Headers/utils.h>

#define MOVE 50

#define COLOR_A CRGB(0, 50, 0)
#define COLOR_B CRGB(0, 0, 255)

void enabledLights(bool enabled, CRGB* leds, uint8_t led_count)
{
	static uint8_t ticks = 0;

	ticks++;
	if (ticks > MOVE*2)
	{
		ticks = 0;
	}

	for (uint8_t i = 0; i < led_count; i++)
	{
		if (divisableBy(i, 3))
		{
			leds[i] = ticks < MOVE ? COLOR_B : COLOR_A;
		}
		else
		{
			leds[i] = ticks < MOVE ? COLOR_A : COLOR_B;
		}
	}
}