#include "main.h"

/**
 * get_environ - function that returns string array copy of environment
 * @info: a pointer to a structure
 *
 * Return: pointer to character array
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - function that removes an environment variable
 * @info: pointer to structure
 * @var: pointer to character array representin variable to unset
 *
 * Return: integer
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t j = 0;
	char *q;

	if (!node || !var)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - function that sets or modifies environment variable,
 * @info: pointer to structure
 * @var: pointer to character array for env variable
 * @value: pointer to character array for value of env variable
 *
 * Return: integer
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *q;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;
	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
