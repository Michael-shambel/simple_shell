#include "main.h"
/**
 *b_free - free a pointer
 *@ptr: adress of pointer
 *
 *Return: 1 if free, or 0
 */
int b_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
