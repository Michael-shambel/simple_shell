#include "shell.h"

/**
 * _memset - function that fills a block of memory with byte value
 * @s: pointer to memory area to be filled
 * @b: byte value to fill the memory area
 * @num: number of bytes to be filled
 * Return: pointer to memory area
 */

char *_memset(char *s, char b, unsigned int num)
{
	unsigned int j;

	for (j = 0; j < num; j++)
		s[j] = b;
	return (s);
}

/**
 * ffree - function that frees memory with allocated strings
 * @qq: pointer to string of array of strings
 *
 * Return:-
 */

void ffree(char **qq)
{
	char **a = qq;

	if (!qq)
		return;
	while (*qq)
		free(*qq++);
	free(a);
}

/**
 * _realloc - function that reallocates block of memory
 * @ptr: pointer to previously allocated memory
 * @old_size: size of previous block
 * @new_size: size of new block
 *
 * Return: pointer to new block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (ptr);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
