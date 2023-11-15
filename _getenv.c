#include "main.h"

/**
 * get_env - function that returns string array copy of environment
 * @info: a pointer to a structure
 *
 * Return: pointer to character array
 */

char **get_env(info_t *info)
{
	if (!info->env || info->env_changed)
	{
		info->env = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->env);
}

/**
 * unset_env - function that removes an environment variable
 * @info: pointer to structure
 * @var: pointer to character array representin variable to unset
 *
 * Return: integer
 */

int unset_env(info_t *info, char *var)
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
 * set_env - function that sets or modifies environment variable,
 * @info: pointer to structure
 * @var: pointer to character array for env variable
 * @value: pointer to character array for value of env variable
 *
 * Return: integer
 */

int set_env(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *q;

	if (!var || !value)
		return (0);

	buff = malloc(strlen(var) + strlen(value) + 2);
	if (!buff)
		return (1);
	strcpy(buff, var);
	strcat(buff, "=");
	strcat(buff, value);
	node = info->env;
	while (node)
	{
		q = starts_with(node->str, var)
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

