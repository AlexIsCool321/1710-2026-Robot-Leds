#include <Headers/ADIndication.h>
#include <Headers/utils.h>

#define SWAP_TICKS 50

#define ATTACKING_COLOR_A CRGB(0, 50, 0)
#define ATTACKING_COLOR_B CRGB(100, 70, 0)


#define DEFENDING_COLOR_A CRGB(50, 0, 0)
#define DEFENDING_COLOR_B CRGB(0, 0, 255)

void ADIndication(bool attacking, CRGB* leds, uint16_t led_count)
{
    static uint16_t ticks = 0;
	
	ticks++;
	if (ticks > SWAP_TICKS * 2)
	{
		ticks = 0;
	}

	CRGB ColorA = attacking ? ATTACKING_COLOR_A : DEFENDING_COLOR_A;
	CRGB ColorB = attacking ? ATTACKING_COLOR_B : DEFENDING_COLOR_B;

	for (uint16_t i = 0; i < led_count; i++)
	{
		if (isOdd(i))
		{
			leds[i] = ticks < SWAP_TICKS ? ColorB : ColorA;
		}
		else
		{
			leds[i] = ticks < SWAP_TICKS ? ColorA : ColorB;
		}
	}
}