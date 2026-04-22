#include <brownOut.h>

#include <brightness.h>

#define RED		getBrightenedColor(CRGB(255, 50, 0))
#define YELLOW	getBrightenedColor(CRGB(100, 50, 0))

#define CHANGE_SPEED 2.5f

#define MAX_TICKS 360

void brownOut(CRGB* pLeds, unsigned int pLedCount)
{
	static float ticks = 0;

	ticks += CHANGE_SPEED;
	if (ticks > MAX_TICKS) ticks = 0;

	float radaint = ticks * (3.14f / 180.0f);
	
	for (unsigned int i = 0; i < pLedCount; i++)
	{
		float sinWave = float((sin(radaint) + 1) / 2);
		unsigned int percentage = 100.0f * sinWave;
		pLeds[i] = colorRange(RED, YELLOW, percentage);
	}
}