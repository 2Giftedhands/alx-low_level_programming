#include "main.h"

/**
 * This code takes a binary string as input, validates that it contains only '0' and '1',
 * and then converts it to its decimal representation using a loop and simple arithmetic operations.
 * If the input is invalid (e.g., contains characters other than '0' and '1' or is a null pointer),
 * the function returns 0 to indicate an error. Otherwise, it returns the converted decimal value.
 */

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
        int i;
        unsigned int dec_val = 0;

        if (!b)
                return (0);

        for (i = 0; b[i]; i++)
        {
                if (b[i] < '0' || b[i] > '1')
                        return (0);
                dec_val = 2 * dec_val + (b[i] - '0');
        }

        return (dec_val);
}
