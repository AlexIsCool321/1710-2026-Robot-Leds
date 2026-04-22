#ifndef SERIAL_H
#define SERIAL_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <stdint.h>

#define RX_PIN 10
#define TX_PIN 11

extern uint8_t communcatedByte;

void setupSerial();
void updateSerial();

#endif