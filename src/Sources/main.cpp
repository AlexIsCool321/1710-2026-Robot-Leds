#include <FastLED.h>
#include <Math.h>
#include <SoftwareSerial.h>

#include <Headers/enabled.h>
#include <Headers/flywheel.h>

#define RX_PIN 0  // RoboRIO TX to Arduino RX
#define TX_PIN 1  // Not needed, but required for SoftwareSerial
#define LED1 7

SoftwareSerial mySerial(RX_PIN, TX_PIN);
// LED setup
#define NUM_LEDS 256

CRGB led[NUM_LEDS];

int command = 20;

// serialEvent function is automatically triggered when data is available on mySerial
void serialEvent() {
	while (mySerial.available()) {
		int receivedByte = mySerial.read();  // Read the incoming byte
		if (receivedByte >= 0) {  // Ensure the byte is valid
			command = receivedByte;  // Update the 'command' with the received byte
		}
	}
}


void setup() {
	mySerial.begin(115200);  // UART communication from RoboRIO
	FastLED.addLeds<WS2812, LED1, RGB>(led, NUM_LEDS); // Some  strips might need to be in the GRB order instead. The black strips we have are RGB, the white ones are GRB.
	FastLED.clear();
	FastLED.show();
}

void loop() {
	enabledLights(false, led, NUM_LEDS);
	FastLED.show();

	delay(1);
}
