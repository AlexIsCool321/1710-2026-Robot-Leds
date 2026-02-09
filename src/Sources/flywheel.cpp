#include <Headers/flywheel.h>

#define CHARGED_COLOR CRGB(255, 0, 0)

#define CHARING_COLOR CRGB(100, 75, 0)
#define UNCHARED_COLOR CRGB(0, 255, 0)

void flywheelChargeLights(uint8_t chargePercentage, CRGB* leds, uint8_t led_count)
{
	CRGB color;

	if (chargePercentage >= 100)
	{
		color = CHARGED_COLOR;
	}
	else
	{
		float percentage = (chargePercentage/10);

		color = CHARING_COLOR * percentage;
		color += UNCHARED_COLOR * (1-percentage);
	}

	for (uint8_t i = 0; i < led_count; i++)
	{
		leds[i] = color;
	}
}
