#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * Finally, the function returns bit_val,
 * which represents the value of the bit at the given index.
 * The value will be either 0 or 1.
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
