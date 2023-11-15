#include "main.h"

/**
 *interactive - check if the intractive mode
 *@info: srtructure adress
 *
 * Return: 1 if it is intractive or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - check for delimeter
 *
 *@car: charcter to check
 *@delimeter: delimeter checker
 *
 *Return: 1 if true, 0 if false
 */
int is_delim(char car, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == car)
			return (1);

	return (0);
}
/**
 *_isalpha - check for alphabetic character
 *@car: input character
 *Return: 1 if it is character
 */
int _isalpha(int car)
{
	if ((car >= 'a' && car <= 'z') || (car >= 'A' && car <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *_atoi - convert a string to integer
 *@s: the string to be converted
 *Return: converted number
 *
 */
int _atoi(char *s)
{
	int x, po_neg = 1, flag = 0, display;
	unsigned int output = 0;

	for (x = 0; s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			po_neg *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			output *= 10;
			output += (s[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (po_neg == -1)
		display = -output;
	else
		display = output;
	return (display);
}
