#include <FastLED.h>
#include <Math.h>
#include <SoftwareSerial.h>

#include <Headers/enabled.h>
#include <Headers/brownOut.h>
#include <Headers/flywheel.h>
#include <Headers/autosVictory.h>
#include <Headers/ADIndication.h>

#define RX_PIN 0  // RoboRIO TX to Arduino RX
#define TX_PIN 1  // Not needed, but required for SoftwareSerial
#define LED1 7

SoftwareSerial mySerial(RX_PIN, TX_PIN);

#define NUM_LEDS 20
CRGB led[NUM_LEDS];

bool autosVictory	= false;
bool BrownOut		= false;
bool Attacking		= false;
uint8_t FlywheelChargePercent = 0;

void serialEvent()
{
	while (mySerial.available())
	{
		uint8_t receivedByte = mySerial.read();
		if (receivedByte >= 0)
		{
			autosVictory	= (receivedByte >> 1) & 1;
			BrownOut		= (receivedByte >> 2) & 1;
			autosVictory	= (receivedByte >> 3) & 1;

			uint8_t charge = (receivedByte & 0x1F) << 3;
			FlywheelChargePercent = (charge / 30) * 100;
		}
	}
}


void setup()
{
	mySerial.begin(115200);
	FastLED.addLeds<WS2812, LED1, RGB>(led, NUM_LEDS);
	FastLED.clear();
	FastLED.show();
}

void loop()
{
	if (autosVictory)	autoVictroy(led, NUM_LEDS);
	if (brownOutLights)	brownOutLights(led, NUM_LEDS);
	ADIndication(Attacking, led, NUM_LEDS);
	flywheelChargeLights(FlywheelChargePercent, led, NUM_LEDS);

	FastLED.show();

	delay(1);
}
