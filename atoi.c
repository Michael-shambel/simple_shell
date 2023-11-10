#include "shell.h"

/**
 *intractive - check for shell intractivity
 *@info: adress
 *
 *Return: 1 of intractive
 */
int intractive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 *is_delim - check char delimiter
 *@car: char to be checked
 *@delim: the delimeter string
 *
 *Return: 1 if char is a delimeter, 0  if it is not
 *
 */
int is_delim(char car, char *delim)
{
	while (*delim)

		if (*delim++ == car)
			return (1);
	return (0);
}
/**
 *_isalpha - check the alphabetic character
 *@car: the character to be chaeked
 *
 * Return: 1 if it is charactr, 0 if it is not
 */
int _isalpha(int car)
{
	if ((car >= 'a' && car <= 'z') || (car >= 'A' && car <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *atoi - conver string to integer
 *
 *@s: the string to be converted
 *
 *Return: converted number or 0 if no input
 */
int atoi(char *s)
{
	int x = 0, signal = 1, pennon = 0, outp;
	unsigned int output = 0;

	while (s[x] != '\0' && pennon != 2)
	{
		if (s[x] == '-')
			signal *= -1;
		if (s[x] >= '0' && s[x] <= '9')
		{
			pennon = 1;
			output *= 10;
			output += (s[x] - '0');
		}
		else if (pennon == 1)
			pennon = 2;
		x++;
	}
	if (signal == -1)
		outp = -output;
	else
		outp = output;
	return (outp);
}
