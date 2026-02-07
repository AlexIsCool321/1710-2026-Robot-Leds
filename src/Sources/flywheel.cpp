#include <Headers/flywheel.h>

void flywheelChargeLights(uint8_t chargePercentage, CRGB* leds, uint8_t led_count)
{
	uint8_t charge_led = (charge_led/100) * led_count;

	for (uint8_t i = 0; i < led_count; i++)
	{
		leds[i] = (i < charge_led) ? CRGB(0, 255, 0) : CRGB(255, 0, 0);
	}
}
