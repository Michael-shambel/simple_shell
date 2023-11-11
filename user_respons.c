#include "shell.h"

/**
 * read_input - reads command input by user
 * @input: pointer address where user input is stored
 * @size: size of buffer to prevent overflow
 * Return:-
 */

void read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_print_stdio("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_print_stdio("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
