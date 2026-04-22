#include <Arduino.h>

#include <disable.h>

#include <brightness.h>

#define RED		getBrightenedColor(CRGB(255, 0, 0))
#define BLUE	getBrightenedColor(CRGB(0, 0, 255))
#define GREEN	getBrightenedColor(CRGB(0, 255, 0))

#define RANDOM_PIN_SEED 0

#define MAX_TICKS 10

void disable(CRGB* pLeds, unsigned int pLedCount)
{
	static unsigned int tick = 0;
	static int index = pLedCount/2;

	randomSeed(analogRead(RANDOM_PIN_SEED));

	tick++;
	if (tick > MAX_TICKS)
	{
		index += random(-1, 2);
		
		tick = 0;
	}

	if (index > pLedCount - 1) index = pLedCount - 1;
	if (index < 1) index = 1;

	for (unsigned int i = 0; i < pLedCount; i++)
	{
		if (i < index)
		{
			pLeds[i] = RED;
		}
		else if (i > index)
		{
			pLeds[i] = BLUE;
		}
		else
		{
			pLeds[i] = GREEN;
		}
	}
}