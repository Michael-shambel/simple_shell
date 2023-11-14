#include "shell.h"

/**
 * clear_info - function that initializes field of structure
 * @info: pointer to structure
 *
 * Return:-
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - function that initializes structure with argv info
 * @info: pointer to structure
 * @av: pointer to string for arguement vector
 *
 * Return:-
 */

void set_info(info_t *info, char **av)
{
	int j = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtok(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (j = 0; info->argv && info->argv[j]; j++)
			info->argc = j;

			replace_alias(info);
			replace_vars(info);
	}
}

/**
 * free_info - function that frees specific fields in structure
 * @info: pointer to strucure
 * @all: integer flag that frees all fields if value is none zero
 *
 * Return:-
 */

void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
