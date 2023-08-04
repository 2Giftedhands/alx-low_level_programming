#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * The function prints the binary representation without leading zeros,
 * and it is limited to handling 64-bit numbers
 * due to the loop's initialization with i = 63.
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
