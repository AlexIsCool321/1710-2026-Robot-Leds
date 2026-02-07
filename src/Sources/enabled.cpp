#include <Headers/enabled.h>
#include <Headers/utils.h>

#define ENABLED_SWAP 50

#define ENABLED_COLOR_A CRGB(0, 50, 0)
#define ENABLED_COLOR_B CRGB(100, 70, 0)


#define DISABLED_SWAP 250

#define DISABLED_COLOR_A CRGB(50, 0, 0)
#define DISABLED_COLOR_B CRGB(0, 0, 255)

void enabledLights(bool enabled, CRGB* leds, uint16_t led_count)
{
	static uint16_t ticks = 0;
	
	int swap_ticks = enabled ? ENABLED_SWAP : DISABLED_SWAP;

	ticks++;
	if (ticks > swap_ticks * 2)
	{
		ticks = 0;
	}

	CRGB ColorA = enabled ? ENABLED_COLOR_A : DISABLED_COLOR_A;
	CRGB ColorB = enabled ? ENABLED_COLOR_B : DISABLED_COLOR_B;

	for (int i = 0; i < led_count; i++)
	{
		if (divisableBy(i, 16))
		{
			leds[i] = ticks < swap_ticks ? ColorB : ColorA;
		}
		else
		{
			leds[i] = ticks < swap_ticks ? ColorA : ColorB;
		}
	}
}