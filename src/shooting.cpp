#include <shooting.h>

#include <brightness.h>

#define GREEN		getBrightenedColor(CRGB(0, 255, 0))
#define GREEN_OFF	getBrightenedColor(CRGB(0, 50, 0))

#define RED		getBrightenedColor(CRGB(255, 0, 0))
#define RED_OFF	getBrightenedColor(CRGB(50, 0, 0))

#define CHANGE_SPEED 5.0f

#define MAX_TICKS 360

void shooting(CRGB* pLeds, unsigned int pLedCount, bool pCanShoot)
{
	static float ticks = 0;
	ticks += CHANGE_SPEED;
	if (ticks > MAX_TICKS) ticks = 0;

	float radaint = ticks * (3.14f / 180.0f);
	
	float sinWave = float((sin(radaint) + 1) / 2);
	unsigned int percentage = 100.0f * sinWave;

	CRGB green	= colorRange(GREEN, GREEN_OFF, percentage);
	CRGB red	= colorRange(RED, RED_OFF, percentage);

	for (unsigned int i = 0; i < pLedCount; i++)
	{
		pLeds[i] = pCanShoot ? green : red;
	}
}