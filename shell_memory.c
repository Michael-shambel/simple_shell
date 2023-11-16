#include "main.h"
/**
 *bfree - free a pointer
 *@ptr: adress of pointer
 *
 *Return: 1 if free, or 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
