#include <Arduino.h>

#include <FastLED.h>
#include <Math.h>
#include <SoftwareSerial.h>

#include <Headers/enabled.h>
#include <Headers/brownOut.h>
#include <Headers/flywheel.h>
#include <Headers/autosVictory.h>
#include <Headers/ADIndication.h>

#define LED1 7
#define INPUT_PIN 3

#define NUM_LEDS 20
CRGB led[NUM_LEDS];


void setup()
{
	pinMode(INPUT_PIN, INPUT);

	FastLED.addLeds<WS2812, LED1, RGB>(led, NUM_LEDS);
	FastLED.clear();
	FastLED.show();
}

void loop()
{
	uint8_t receivedByte = digitalRead(INPUT_PIN);
	/*
	 * 0	Flywheel Charge
	 * 1	Flywheel Charge
	 * 2	Flywheel Charge
	 * 3	Flywheel Charge
	 * 4	Flywheel Charge
	 * 5	Flywheel Charge
	 * 6	Autos Victroy
	 * 7	Brown Out
	 * 8	Autos Victory
	*/

	bool autosVictory	= (receivedByte >> 8) & 1;
	bool BrownOut		= (receivedByte >> 7) & 1;
	bool Attacking		= (receivedByte >> 6) & 1;

	uint8_t FlywheelChargePercent = (receivedByte << 3) >> 3; // Clears last 3 bits
	FlywheelChargePercent = (FlywheelChargePercent / 30) * 100;


	if (BrownOut) brownOutLights(led, NUM_LEDS);
	ADIndication(Attacking, led, NUM_LEDS);

	if (autosVictory) autoVictroy(led, NUM_LEDS);
	flywheelChargeLights(FlywheelChargePercent, led, NUM_LEDS);

	FastLED.show();

	delay(1);
}
