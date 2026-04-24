#include <serial.h>

#include <Arduino.h>

uint8_t communicatedByte = 0;

volatile uint8_t rxByte = 0;
volatile bool newData = false;

void setupSerial()
{
	Serial.begin(9600);

	pinMode(MISO, OUTPUT); // required for slave

	// Enable SPI in slave mode
	SPI0.CTRLA = 0; // disable first
	SPI0.CTRLB = SPI_SSD_bm; // slave select disable (optional depending on wiring)
	SPI0.INTCTRL = SPI_IE_bm; // enable interrupt
	SPI0.CTRLA = SPI_ENABLE_bm; // enable SPI
}

// Correct interrupt vector for ATmega4809
ISR(SPI0_INT_vect)
{
	rxByte = SPI0.DATA;
	SPI0.DATA = rxByte + 1;

	newData = true;

	SPI0.INTFLAGS = SPI_IF_bm; // clear interrupt flag
}

void updateSerial()
{
	if (newData)
	{
		Serial.println(rxByte);
		communicatedByte = rxByte;

		newData = false;
	}

	if (Serial.available())
	{
		Serial.readBytes(&communicatedByte, 1);
	}
}