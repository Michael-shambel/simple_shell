#include "shell.h"
/**
 * _print_stdio - print the function
 * @print: character to be printed
 *
 * Return: Nothing
 */

void _print_stdio(const char *print)
{
	write(STDOUT_FILENO, print, strlen(print));
}

