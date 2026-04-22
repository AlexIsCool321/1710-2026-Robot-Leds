#include <Arduino.h>

#include <FastLED.h>
#include <Math.h>

#include <serial.h>

#include <brownOut.h>
#include <intaking.h>
#include <shooting.h>
#include <autosVictory.h>
#include <disable.h>
#include <idle.h>

#define TICK_INTERVAL 10

#define COLOR_ORDER GRB

#define LED_PIN 5
#define NUM_LEDS 55

// 23'' 35 leds back
// 8''	12 leds sides

CRGB* leds;

void setup()
{
	leds = (CRGB*)malloc(sizeof(CRGB) * NUM_LEDS);

	setupSerial();

	FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.clear();
	FastLED.show();
}

void loop()
{
	updateSerial();

	idle(leds, NUM_LEDS);
	//	128	64	32	16	|	8	4	2	1
	//	0	0	0	0	|	0	0	0	0

	if (communcatedByte & (1 << 0)) disable(		leds,	NUM_LEDS);									// 1	0000 0001
	if (communcatedByte & (1 << 1)) autosVictory(	leds,	NUM_LEDS, (communcatedByte & (1 << 2)));	// 2	0000 0X10
	if (communcatedByte & (1 << 3)) brownOut(		leds,	NUM_LEDS);									// 8	0000 1000
	if (communcatedByte & (1 << 4)) intaking(		leds,	NUM_LEDS);									// 15	0001 0000
	if (communcatedByte & (1 << 5)) shooting(		leds,	NUM_LEDS, (communcatedByte & (1 << 6)));	// 32	0X10 0000

	FastLED.show();
	delay(TICK_INTERVAL);
}