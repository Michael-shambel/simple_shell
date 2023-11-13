#include "main.h"

/**
 *print_env - orint the current envirnment
 *@info: structure argument
 *
 * Return: always zero
 */
int print_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 *_getenv - get the value of an environment
 *@info: structure argument
 *@name: name of environment
 *
 *Return: NULL
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pointer;

	while (node)
	{
		pointer = starts_with(node->str, name);
		if (pointer && *pointer)
			return (pointer);
		node = node->next;
	}
	return (NULL);
}
/**
 *_initenv - Iniatialize a new environmet
 *@info: structure argument
 *
 * Return: always zero
 */
int _initenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 *_remenv - remove an environment
 *@info: structure argument
 *
 * Return: always 0
 */
int _remenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
	return (0);
}
/**
 *_popenv - populate environment
 *@info: structure argument
 *
 * Return: always zero
 */
int _popenv(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
