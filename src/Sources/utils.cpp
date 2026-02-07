#include <Headers/utils.h>

bool isOdd(uint8_t value) {
	return (value & 1) == 1;
}

bool divisableBy(uint8_t value, uint8_t divisor)
{
	return (value % divisor) == 0;
}