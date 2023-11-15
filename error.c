#include "main.h"

/**
 *_eputs - print an input string
 *@string: string to be printed
 *
 * Return: void
 */
void _eputs(char *string)
{
	int x = 0;

	if (!string)
		return;
	while (string[x] != '\0')
	{
		_eputchar(string[x]);
		x++;
	}
}
/**
 *_eputchar - write the character
 *@car: character to be printed
 *
 * Return: On success 1
 */
int _eputchar(char car)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (car == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buffer, x);
		x = 0;
	}
	if (car != BUF_FLUSH)
		buffer[x++] = car;
	return (1);
}
/**
 *_putfd - writes the character
 *@car: the character to print
 *@fd: the file discriptor
 *
 * Return: On success 1, -1 on error
 */
int _putfd(char car, int fd)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (car == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, x);
		x = 0;
	}
	if (car != BUF_FLUSH)
		buffer[i++] = car;
	return (1);
}
/**
 *_putsfd - print a string
 *@string: string to be printed
 *@fd: file discriptor
 *
 * Return: number of chars
 */
int _putsfd(char **string, int fd)
{
	int x = 0;

	if (!string)
		return (0);
	while (*string)
	{
		x = x + _putfd(*string++, fd);
	}
	return (1);
}
