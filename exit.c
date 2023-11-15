#include "main.h"

/**
 * _strncpy - function that copies characters
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @num: max. number of characters to be copied
 *
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int num)
{
	int a, b;
	char *en = dest;

	a = 0;
	while (src[a] != '\0' && a < num - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < num)
	{
		b = a;
		while (b < num)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (en);
}

/**
 * _strncat - function that concatenates two strings
 * @dest: pointer to destination string
 * @src: ponter to a source string
 * @num: max number of characters
 *
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int num)
{
	int a, b;
	char *entry = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < num)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < num)
		dest[a] = '\0';
	return (entry);
}

/**
 * _strchr - function that locates a character in a string
 * @str: pointer to string to be passed
 * @c: character to be searched for in string
 *
 * Return: pointer to first occurrence of character 'c'
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
