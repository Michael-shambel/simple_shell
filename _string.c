#include "main.h"

/**
 * _strlen - length of a string
 * @string: the string whose length to check
 *
 * Return: length of string
 */
int _strlen(char *string)
{
	int x = 0;

	if (!string)
		return (0);

	while (*string++)
		x++;
	return (x);
}

/**
 * _strcmp - comparison of two strangs.
 * @string1: first strang
 * @string2: second strang
 *
 * Return: negative, positive or zero
 */
int _strcmp(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @hay_stack: string to search
 * @_needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *hay_stack, const char *_needle)
{
	while (*_needle)
		if (*_needle++ != *hay_stack++)
			return (NULL);
	return ((char *)hay_stack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destination, char *source)
{
	char *resp = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (resp);
}
