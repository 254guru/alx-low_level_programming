#include "main.h"
/**
 * get_endianess - checks for endianess
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) & i;

	return (*c == 1);
}
