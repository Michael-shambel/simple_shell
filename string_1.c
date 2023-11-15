#include "main.h"

/**
 * _strcpy - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
	int x = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[x])
	{
		destination[x] = source[x];
		x++;
	}
	destination[x] = 0;
	return (destination);
}

/**
 * _strdup - duplicates a string
 * @string: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *string)
{
	int len = 0;
	char *resp;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	resp = malloc(sizeof(char) * (len + 1));
	if (!resp)
		return (NULL);
	for (len++; len--;)
		resp[len] = *--string;
	return (resp);
}

/**
 *_puts - prints string
 *@string: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *string)
{
	int x = 0;

	if (!string)
		return;
	while (string[x] != '\0')
	{
		_putchar(string[x]);
		x++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @car: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char car)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (car == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buffer, x);
		x = 0;
	}
	if (car != BUF_FLUSH)
		buffer[x++] = car;
	return (1);
}
