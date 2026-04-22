#include <autosVictory.h>

#include <brightness.h>

#define GREEN		getBrightenedColor(CRGB(0, 255, 0))
#define GREEN_OFF	getBrightenedColor(CRGB(0, 50, 0))

#define RED		getBrightenedColor(CRGB(255, 0, 0))
#define RED_OFF	getBrightenedColor(CRGB(50, 0, 0))


#define MAX_TICKS 200

void autosVictory(CRGB* pLeds, unsigned int pLedCount, bool pWin)
{
	static unsigned int ticks = 0;

	if (ticks > MAX_TICKS) ticks = 0;
	ticks++;

	float percentage = float(ticks) / float(MAX_TICKS);

	unsigned int divider = float(pLedCount) * percentage;

	for (unsigned int i = 0; i < pLedCount; i++)
	{
		CRGB on		= pWin ? GREEN : RED;
		CRGB off	= pWin ? GREEN_OFF : RED_OFF;

		if (i <= divider)
		{
			pLeds[i] = on;
		}
		else
		{
			pLeds[i] = off;
		}
	}
}