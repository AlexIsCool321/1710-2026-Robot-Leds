#include <idle.h>

#include <brightness.h>

CRGB colors[3] =
{
	getBrightenedColor(CRGB(255, 255, 255)),	// WHITE
	getBrightenedColor(CRGB(0, 0, 255)),		// BLUE
	getBrightenedColor(CRGB(10, 10, 10))		// BLACK
};

#define MAX_TICKS 10

void idle(CRGB* pLeds, unsigned int pLedCount)
{
	static unsigned int tick = 0;
	static unsigned int index = 0;
	static unsigned int colorIndex = 0;

	tick++;
	if (tick > MAX_TICKS)
	{
		index++;
		
		tick = 0;
	}

	if (index > pLedCount)
	{
		index = 0;

		colorIndex++;

		if (colorIndex > 2) colorIndex = 0;
	}

	pLeds[index] = colors[colorIndex];
}