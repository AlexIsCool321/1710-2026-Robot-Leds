#include <FastLED.h>
#include <Math.h>
#include <SoftwareSerial.h>

#include <Headers/enabled.h>
#include <Headers/flywheel.h>
#include <Headers/autosVictory.h>

#define RX_PIN 0  // RoboRIO TX to Arduino RX
#define TX_PIN 1  // Not needed, but required for SoftwareSerial
#define LED1 7

SoftwareSerial mySerial(RX_PIN, TX_PIN);

#define NUM_LEDS 20
CRGB led[NUM_LEDS];

int command = 20;

void serialEvent()
{
	while (mySerial.available())
	{
		int receivedByte = mySerial.read();
		if (receivedByte >= 0)
		{
			command = receivedByte;
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
	//enabledLights(false, led, NUM_LEDS);
	//autoVictroy(led, NUM_LEDS);
	flywheelChargeLights(0, led, NUM_LEDS);

	FastLED.show();

	delay(1);
}
