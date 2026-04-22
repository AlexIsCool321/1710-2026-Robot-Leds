#include <intaking.h>

#include <brightness.h>

#define PURPLE getBrightenedColor(CRGB(110, 0, 255))
#define WHITE getBrightenedColor(CRGB(150, 150, 150))

#define MAX_TICKS 100

void intaking(CRGB* pLeds, unsigned int pLedCount)
{
	static unsigned int ticks = 0;

	ticks++;
	if (ticks > MAX_TICKS) ticks = 0;

	bool alternate = (ticks > (MAX_TICKS / 2));
	
	CRGB ColorA = alternate ? PURPLE : WHITE;
	CRGB ColorB = alternate ? WHITE : PURPLE;

	for (unsigned int i = 0; i < pLedCount; i++)
	{
		bool isOdd = float(i) / 2.0f == i / 2;
		
		pLeds[i] = isOdd ? ColorA : ColorB;
	}
}