#include "shell.h"

/**
 *impliment_command - is to execute the prompt
 *@order: is command to be executed
 *Return: always 0
 */
void impliment_command(const char *order)
{
	pid_t ch_pid = fork();

	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (ch_pid == 0)
	{
		execlp(order, order, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
