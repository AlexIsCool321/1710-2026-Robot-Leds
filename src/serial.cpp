#include <serial.h>

#define DEBUG 1

SoftwareSerial communicationSerial(RX_PIN, TX_PIN);
uint8_t communcatedByte = 0;

void setupSerial()
{
	Serial.begin(9600);
	communicationSerial.begin(57600); // 115200?
	
	Serial.println("Serial started");
}

void updateSerial()
{
#if DEBUG
	
	if (Serial.available() > 0)
	{
		communcatedByte = Serial.read();
		
		Serial.print("Received: ");
		Serial.println(communcatedByte);
	}

#else

	if (communicationSerial.available() > 0)
	{
		communcatedByte = communicationSerial.read();
		
		communicationSerial.print("Received: ");
		communicationSerial.println(communcatedByte);

		Serial.println(communcatedByte);
	}

#endif
}