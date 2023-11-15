#include "main.h"

/**
 * _erratoi - function that converts string into integer
 * @s: string to be converted
 *
 * Return: 0 if successful -1 if failure
 */

int _erratoi(char *s)
{
	int j = 0;
	unsigned long int outcome = 0;

	if (*s == '+')
		s++;

	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			outcome *= 10;
			outcome += (s[j] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * print_error - function that prints error name
 * @info: the pointer to structure
 * @estr: pointer to string containing error type
 *
 * Return: 0 if success -1 if failure
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints a decimal
 * @input: number to be printed
 * @fd: file descriptor to write stdout an stderr
 *
 * Return: number of characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int _abs, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs = -input;
		__putchar ('-');
		counter++;
	}
	else
		_abs = input;
	current = _abs;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs / j)
		{
			__putchar('0' + current / j);
			counter++;
		}
		current %= j;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 * convert_number - function that converts
 * @num: number to be converted
 * @base: base for conversion
 * @flags: flags for conversion process
 *
 * Return: pointer to converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buff[50];
	char sign = 0;
	char *pointer;
	unsigned long k = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		k = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buff[49];
	*pointer = '\0';

	do	{
		*--pointer = array[k % base];
		k /= base;
	} while (k != 0);

	if (sign)
		*--pointer = sign;
	return (pointer);
}

/**
 * remove_comments - function that replaces 1st instance of '#' with '0'
 * @buffer: pointer to string to be modified
 *
 * Return: 0;
 */

void remove_comments(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != '\0'; j++)
		if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
		{
			buffer[j] = '\0';
			break;
		}
}
